#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("scribe");
    feat_syntax("scribe CAST_LEVEL SPELL_NAME");
    feat_prereq("Mage or Sorcerer");
    feat_desc("This feat allows a character to use their knowledge of the arcane to scribe simple scrolls of spells they already know. Such scrolls are only good for a single use.
     
CAST_LEVEL

    The effective caster level of the spell you are. This cannot be higher than your caster level. Higher the level higher spellcraft is required to use the scroll.

SPELL_NAME

    The spell you wish the scroll to cast when it is used.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("mage") && !ob->is_class("sorcerer")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_scribe(string str) {
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { str = ""; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

object find_compbag(string component, int amount, object tp) {
   object compBag;

   int i = 1;
   while (compBag = present("compx "+i, tp)){
      if ((int)compBag->query_comp(component) >= amount) return compBag;
      i++;
   }
}

/**
 * Maximum level for enchanted spells to cast
 */
int maximum_enchant_level()
{
    return max(({caster->query_guild_level("mage"),caster->query_guild_level("sorcerer")}))+
        (int)caster->query_property("empowered");
}

void execute_feat() 
{
    object ob, tp;
    int level, number;
    string tmp, str, levelstring;

    if(!arg) return help();
    if (sscanf (arg, "%d %s", number, str) !=2) return help();
    if(number > maximum_enchant_level())
    {
        tell_object(caster, "%^BOLD%^%^RED%^Maximum scribe level for you is: "+max(({maximum_enchant_level("mage"),maximum_enchant_level("sorcerer")})));
        return 1;
    }

    tmp = "/cmds/spells/"+str[0..0]+"/_"+replace_string(str," ","_");
    if(!objectp(find_object_or_load(tmp))) { tell_object(caster,"You don't know a spell named "+str+"."); return 1; }
    level = tmp->query_spell_level("mage");
    levelstring = "level "+level;

    if(caster->is_class("mage") && !caster->query_memorized("mage",str)) 
    {
        tell_object(caster, "That spell isn't memorized.\n");
        return 1;
    }
    if(caster->is_class("sorcerer") && !caster->query_memorized("sorcerer",levelstring)) 
    {
        tell_object(caster, "You haven't prepared any spells of that level.\n");
        return 1;
    }

    ob = present("parchment11", caster);
    if (!objectp(ob = present("parchment11", caster)) )
    {
        tell_object(caster, "You don't have any parchment!");
        return 1;
    }

    if((int)SAVE_D->is_member("scribe_restricted",caster->query_name()) != -1) 
    {
        tell_object(caster, "%^BOLD%^%^WHITE%^Your use of this ability has been "+
            "restricted for inappropriate use.");
        return 1;
    }        

    tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" sits and begins to scribe a spell onto some parchment.",caster);
    tell_object(caster, "%^BOLD%^You sit and start to scribe "+str+" onto the parchment.");

    call_out("scribe",level*2, str, caster, ob, number);
    caster->set_paralyzed(level*2,"You are scribing the spell.");
    tell_object(caster, "Hit <return> to cancel. This will waste the parchment.");
    input_to("cancel",1,ob, str);
    return;
}

void cancel(object ob, string spell){
    if (!objectp(ob)) {
        return;
    }
    ob->remove();
    write("You interrupt your scribing.");
    tell_room(environment(caster),""+caster->QCN+" interrupts "+caster->QP+" attempt to scribe a new scroll.",caster);
    caster->remove_paralyzed();
    remove_call_out("scribe");
}

void scribe(string spell, object tp, object paper, int number){
    object scroll, compbag;
    string tmp, *comp_names;
    mapping components;
    int x;

    if(!objectp(paper)) { return 0; }
    if(!objectp(tp)) { return 0; }

    tmp = "/cmds/spells/"+spell[0..0]+"/_"+replace_string(spell," ","_");
    if (!(present("compx", tp)) && sizeof(tmp->query_components("mage")) > 0) {
        tell_player(tp, "You need a components bag with components to scribe this spell.");
        tp->remove_paralyzed();
        tell_object(tp,"Hit <return> to continue.");
        return;
    }

    components = tmp->query_components("mage");
    if (components) comp_names = keys(components);
    //Check to see if the proper components are in place
    for (x=0;x<sizeof(comp_names);x++) {
        if (!components) break;
        if (!(find_compbag(comp_names[x], components[comp_names[x]],tp))) {
            tell_object(tp, "You do not have the required components for this spell!\n");
            tp->remove_paralyzed();
            tell_object(tp,"Hit <return> to continue.");
            return;
        }
    }

    for (x=0;x<sizeof(comp_names);x++) {
        if (!components) break;
        compbag = find_compbag(comp_names[x], components[comp_names[x]],tp);
        compbag->use_comp(comp_names[x],components[comp_names[x]]);
   }

    tell_object(tp,"%^BOLD%^You finish scribing "+spell+".");
    tell_room(environment(tp),"%^BOLD%^"+tp->query_cap_name()+" finishes "+tp->QP+" scribing.",tp);
    scroll = new ("/d/magic/scroll");
    scroll->set_spell_name(spell);
    scroll->set_spell_level(number);
    scroll->set_passed((string)tp->query_name()); //let scribers automatically read their own scrolls. Nienne, 07/09.
    scroll->move(environment(tp));
    if(tp->is_class("mage")) 
    {
        tp->forget_memorized("mage",spell);
    }
    else 
    {
        tp->forget_memorized("sorcerer",spell);
    }
    tp->remove_paralyzed();
    paper->remove();
    tell_object(tp,"Hit return to continue.");
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}


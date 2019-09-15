#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("scribe");
    feat_syntax("scribe SPELL_NAME");
    feat_prereq("Mage, Sorcerer, Cleric, Bard, Paladin");
    feat_desc("This feat allows a character to use their knowledge of the arcane to scribe simple scrolls of spells they already know. Such scrolls are only good for a single use. You must have an empty parchment sheet in your inventory for scribe to work. It has to be parchment, other writing materials won't do.

SPELL_NAME
    The spell you wish the scroll to cast when it is used.

%^BOLD%^N.B.%^RESET%^ Multiclassing characters will use currently posed class for this feat. Use <pose> to switch it.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("mage") &&
       !ob->is_class("sorcerer") &&
       !ob->is_class("cleric") &&
       !ob->is_class("bard") &&
       !ob->is_class("paladin"))
    {
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

void execute_feat()
{
    object ob, tp;
    int level, number;
    string tmp, str, levelstring;

    if(!arg) return help();
    if (sscanf (arg, "%s", str) !=1) return help();

    tmp = MAGIC_D->get_spell_file_name(str);
    if(!objectp(find_object_or_load(tmp))) { tell_object(caster,"You don't know a spell named "+str+"."); return 1; }
    level = tmp->query_spell_level(TP->query_class());

    if(!caster->query_memorized(TP->query_class(),str))
    {
        tell_object(caster, "That spell isn't memorized.\n");
        return 1;
    }

    ob = present("parchment11", caster);
    if (!objectp(ob = present("parchment11", caster)) )
    {
        tell_object(caster, "You don't have any parchment!");
        return 1;
    }

    tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" sits and begins to scribe a spell onto some parchment.",caster);
    tell_object(caster, "%^BOLD%^You sit and start to scribe "+str+" onto the parchment.");

    call_out("scribe",level*2, str, caster, ob);
    caster->set_paralyzed(level*2*8,"You are scribing the spell.");
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

void scribe(string spell, object tp, object paper){
    object scroll, compbag;
    string tmp, *comp_names;
    int x;

    if(!objectp(paper)) { return 0; }
    if(!objectp(tp)) { return 0; }

    tell_object(tp,"%^BOLD%^You finish scribing "+spell+".");
    tell_room(environment(tp),"%^BOLD%^"+tp->query_cap_name()+" finishes "+tp->QP+" scribing.",tp);
    scroll = new ("/d/magic/scroll");
    scroll->set_spell_name(spell);
    scroll->set_passed((string)tp->query_name()); //let scribers automatically read their own scrolls. Nienne, 07/09.
    scroll->move(environment(tp));
    tp->remove_paralyzed();
    paper->remove();
    tell_object(tp,"Hit return to continue.");
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

string arg;
int theProf;
object targ;

void dispel(object ob);
int checkDispel(object ob);

void create() {
    ::create();
    set_spell_name("dispel magic");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "paladin" : 3, "bard" : 3,"druid" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS dispel magic (on TARGET)");
    set_description("Dispel Magic, when cast, will destroy any spell enchantments, any magical summonings, and anything "
"conjured.  The chances of each dispelling depends on both the dispeller's casting level and the casting level of the "
"wizard or priest that created whatever is being dispelled, whether it be an enchantment, summoning, or conjuration.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return caster->QCN+" raises "+caster->QP+" arms and calls for mystic assistance!";
}

int preSpell() {
    if (!query_arg()) return 1;
    targ = present(query_arg(), query_place());
    if (!targ) {
        tell_object(query_caster(), "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object *allinv;
    int i;
    theProf = prof;

    caster = query_caster();
    place = query_place();
    arg = query_arg();

    tell_room(place, "%^BOLD%^The air shimmers as "+caster->QCN+" %^BOLD%^%^WHITE%^completes a spell.", caster);
    tell_object(caster, "%^BOLD%^The air in the area begins to shimmer.");

    if (targ && !objectp(targ)) {  // if there was a target set but it's gone, dispel
        dest_effect();
        return;
    }
    if(targ && !caster->ok_to_kill(targ)) {   // fixed from target *Styx* 1/25/05
        dest_effect();
        return;
    }
    if (!targ) {  // now, if there wasn't a target set, do the room
        allinv = deep_inventory(place);
        allinv = target_filter(allinv);
        allinv += ({place});
      } else {
        allinv = deep_inventory(targ);
        allinv += ({targ});
    }

    for (i = 0;i < sizeof(allinv);i++) {
        if (!objectp(allinv[i])) continue;
        if(!caster->ok_to_kill(allinv[i])) continue;
        if (allinv[i]->query_property("spelled"))
            dispel(allinv[i]);
    }
    dest_effect();
    return 1;
}

void dispel(object ob) {
    object *spells;
    int i;

    if(!objectp(ob)) { return; }

    if(!ob->query_property("spelled") )
        return;
    if(ob->query_true_invis()) {
        return;
    }

    if (pointerp(ob->query_property("spelled")))
        spells = ob->query_property("spelled");
    else
        spells = ({ob->query_property("spelled")});

    if (spells == ({}))
        return;

    for (i = 0;i<sizeof(spells);i++) 
    {
        if(!objectp(ob)) { continue; }
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) {
            continue;
        }
        tell_object(caster, "You dispel the "+spells[i]->query_spell_name());
        ob->remove_property_value("spelled", ({spells[i]}) );
        spells[i]->dest_effect();
    }

    return;
}

// gets the difference in the casting stat modifier for the dispeller and the caster of the target spell
// stat - 10 / 2   returns target's stat mod - caster's stat mod
// Adapted by ~Circe~ 9/16/11 to use new standard coding in /std/magic/spell.c to make sure 
// bonuses are correctly applied for every class.

int get_stat_mod_difference(object obj,object cast){
    object targ;
    string name,targ_stat,cast_stat;
    int mod_targ,mod_cast;

    if(!objectp(obj)) { return 0; }
    if(!objectp(cast)) { return 0; }

    targ = (object)obj->query_caster();

    if(!objectp(targ)) { return 0; }

    name = base_name(obj);
    targ_stat = obj->query_casting_stat();
    cast_stat = casting_stat;
    mod_targ = ((int)targ->query_stats(targ_stat) - 10) / 2;
    mod_cast = ((int)cast->query_stats(cast_stat) - 10) / 2;
//    tell_room(place,"Caster's stat is "+cast_stat+" and "+caster->QP+" bonus is "+mod_cast+".");
//    tell_room(place,"Target's stat is "+targ_stat+" and "+caster->QP+" bonus is "+mod_targ+".");
    return mod_targ - mod_cast;
}

// dice roll to dispell is d20 vs 10 + level difference between caster and target + difference in 
// casting stat mods + the level of the spell
int checkDispel(object ob) 
{
    int roll, level_diff,DC,stat_weight,sp_lvl,buffered;
    object mycast;

    if(!objectp(ob)) { return 0; }
    if(TO->query_caster() == ob->query_caster()) return 1;

    mycast = ob->query_caster();
    if(!objectp(mycast)) { return 0; }

    level_diff = (int)ob->query_clevel() - (int)TO->query_clevel();

    stat_weight = get_stat_mod_difference(ob,(object)TO->query_caster());

    sp_lvl = (int)ob->query_spell_level();

    DC = 10 + sp_lvl + level_diff + stat_weight;

// +2 bonus vs dispels for shadow adepts, if the dispeller is not also a shadow weave user.
    if(FEATS_D->usable_feat(ob->query_caster(),"elusive spellcraft") && !FEATS_D->usable_feat(TO->query_caster(),"elusive spellcraft")) DC += 2;
    
    if(mycast->query_property("dispelling_buffer") > 0){
       buffered = mycast->query_property("dispelling_buffer");
//       tell_object(mycast,"DC before buffer: "+DC+"");
       DC += buffered;
//       tell_object(mycast,"DC after buffer: "+DC+"");
    }

    roll = roll_dice(1,20);
//    tell_object(mycast,"Roll: "+roll+" vs. DC: "+DC+"");

    if(roll >= DC) { return 1; }
    else { return 0; }
}


void reverse_spell(){
    set_arg(caster->query_name());
    spell_effect(FULL_EFFECT);
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

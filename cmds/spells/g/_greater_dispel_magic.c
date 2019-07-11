// Greater Dispel Magic
// Works just like regular dispel magic, but it assumes that the
// caster is 10 levels higher for the purpose of dispelling.  -Ares
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
string arg;
object targ;

void dispel(object ob);
int checkDispel(object ob);

void create() {
    ::create();
    set_spell_name("greater dispel magic");
    set_spell_level(([ "mage" : 7, "bard" : 5, "cleric" : 6,"druid" : 6 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS greater dispel magic [on TARGET]");
    set_description("Greater Dispel Magic is a significantly more powerful version of the 3rd level spell, Dispel Magic.  "
"When cast it will attempt to destroy any spell enchantments, magical summonings, and anything conjured.  The chances of "
"each dispelling depends on both the dispeller's casting level and the power level of the spellcaster that created "
"whatever is being dispelled, whether it be an enchantment, summoning, or conjuration.");
    set_verbal_comp();
    //this - set_arg_needed() was missing and thus
    //it was returning in preSpell() before the targ was ever set... 
    //so there was no target ever being set - so it would just
    //assume you meant to cast it on the room - fixed now - Saide
    set_arg_needed();
    set_somatic_comp();
}

string query_cast_string() {
    tell_object(caster,"%^RED%^The air around you begins to ripple "+
		"as you wave your hands about.");
    tell_room(place,"%^RED%^The air around "+caster->QCN+" begins to ripple"+
		" as "+caster->QS+" waves "+caster->QP+" hands about.",caster);
	return("display");
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

    caster = query_caster();
    place = query_place();
    clevel = query_clevel() + 10;
    arg = query_arg();

    tell_room(place, "%^BLUE%^The rippling spreads from "+caster->QCN+".",caster);

    tell_object(caster, "%^BLUE%^The rippling spreads outwards from you.");
    if (targ && !objectp(targ)) 
    { 
        dest_effect();
        return;
    }
    if(targ && !caster->ok_to_kill(targ)) 
    {  
        dest_effect();
        return;
    }
    if (!targ) 
    {
        allinv = deep_inventory(place);
        allinv += ({place});
        allinv = target_filter(allinv);
    } 
    else 
    {	
        allinv = deep_inventory(targ);
        allinv += ({targ});
    }

    for (i = 0;i < sizeof(allinv);i++) 
    {
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

    if(!ob->query_property("spelled")) return;

    if(pointerp(ob->query_property("spelled")))
        spells = ob->query_property("spelled");
    else
        spells = ({ob->query_property("spelled")});

    if(spells == ({})) return;

    for (i = 0;i<sizeof(spells);i++) {
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) {
            tell_object(caster, "You are unable to dispel the "+spells[i]->query_spell_name());
            continue;
        }
        tell_object(caster, "You dispel the "+spells[i]->query_spell_name());
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

    return mod_targ - mod_cast;
}

// dice roll to dispell is d20 vs 10 + level difference between caster and target + difference in 
// casting stat mods + the level of the spell
int checkDispel(object ob) 
{
    int roll, level_diff,DC,stat_weight,sp_lvl,buffered;
    object mycast;

    if(TO->query_caster() == ob->query_caster()) return 1;

    mycast = ob->query_caster();
    if(!objectp(mycast)) return 1;
    level_diff = (int)ob->query_clevel() - clevel;

    stat_weight = get_stat_mod_difference(ob,(object)TO->query_caster());

    sp_lvl = (int)ob->query_spell_level();

    DC = 10 + sp_lvl + level_diff + stat_weight;

// +2 bonus vs dispels for shadow adepts, if the dispeller is not also a shadow weave user.
    if(FEATS_D->usable_feat(mycast,"shadow adept") && !FEATS_D->usable_feat(TO->query_caster(),"shadow adept")) DC += 2;
    if(FEATS_D->usable_feat(ob->query_caster(),"elusive spellcraft") && !FEATS_D->usable_feat(TO->query_caster(),"elusive spellcraft")) DC += 2;

    if(mycast->query_property("dispelling_buffer") > 0){
       buffered = mycast->query_property("dispelling_buffer");
//       tell_object(mycast,"DC before buffer: "+DC+"");
       DC += buffered;
//       tell_object(mycast,"DC after buffer: "+DC+"");
    }

    roll = roll_dice(1,20);
//    roll += 4; // bonus for greater dispel
// this shouldn't be here - we already have a +10 at the start!

    if(roll >= DC) { return 1; }
    else { return 0; }
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
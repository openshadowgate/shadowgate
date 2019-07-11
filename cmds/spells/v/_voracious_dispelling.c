#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

string arg;
int theProf;
object caster, place, targ;

void dispel(object ob);
int checkDispel(object ob);

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("voracious dispelling");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("cast CLASS voracious dispelling (on TARGET)");
    set_description("This invocation will seek to unravel any spell enchantments, magical summonings, and conjurations. "
"The chances of each dispelling depends on both the dispeller's power, and that of the one who created whatever is being "
"dispelled. Such is the disruptive nature of the invocation, that successful dispel attempts will also harm their target.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^Your hands tremble with %^BOLD%^%^BLACK%^di%^RESET%^sr%^BOLD%^%^BLACK%^u%^RESET%^pt%^BOLD%^%^BLACK%^iv%^RESET%^e %^BOLD%^%^WHITE%^potential.%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s hands tremble with %^BOLD%^%^BLACK%^di%^RESET%^sr%^BOLD%^%^BLACK%^u%^RESET%^pt%^BOLD%^%^BLACK%^iv%^RESET%^e %^BOLD%^%^WHITE%^potential.%^RESET%^",caster);
    return "display";
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

    tell_room(place, "%^BOLD%^%^WHITE%^"+caster->QCN+" releases the invocation in a burst of c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energy!%^RESET%^", caster);
    tell_object(caster, "%^BOLD%^%^WHITE%^You release the invocation in a burst of c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energy!%^RESET%^");

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
    }
    else {
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
}

void dispel(object ob) {
    object *spells;
    int i, dmg, mylvl;
    string mytype;

    if(!objectp(ob)) { return; }

    if(!ob->query_property("spelled")) return;
    if(ob->query_true_invis()) return;

    if (pointerp(ob->query_property("spelled"))) spells = ob->query_property("spelled");
    else spells = ({ob->query_property("spelled")});

    if (spells == ({})) return;

    dmg = 0;
    for (i = 0;i<sizeof(spells);i++) {
        if(!objectp(ob)) continue;
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) continue;
        tell_object(caster, "You dispel the "+spells[i]->query_spell_name());
        mytype = spells[i]->query_spell_type();
        mylvl = spells[i]->query_spell_level(mytype);
        if(mylvl < 1) mylvl = 1;
        dmg += (mylvl*2); // we're going to do 2 damage per spell level dispelled, to the target
        ob->remove_property_value("spelled", ({spells[i]}) );
        spells[i]->dest_effect();
    }
    if(dmg) {
      tell_object(ob,"%^BOLD%^%^WHITE%^The c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energies tear at your body!%^RESET%^");
      damage_targ(ob,"torso",dmg,"untyped");
    }
}

// gets the difference in the casting stat modifier for the dispeller and the caster of the target spell
// stat - 10 / 2   returns target's stat mod - caster's stat mod
// Adapted by ~Circe~ 9/16/11 to use new standard coding in /std/magic/spell.c to make sure 
// bonuses are correctly applied for every class.

int get_stat_mod_difference(object obj,object cast){
    object targ;
    string name,targ_stat,cast_stat;
    int mod_targ,mod_cast;

    if(!objectp(obj)) return 0;
    if(!objectp(cast)) return 0;

    targ = (object)obj->query_caster();

    if(!objectp(targ)) return 0;

    name = base_name(obj);
    targ_stat = obj->query_casting_stat();
    cast_stat = casting_stat;
    mod_targ = ((int)targ->query_stats(targ_stat) - 10) / 2;
    mod_cast = ((int)cast->query_stats(cast_stat) - 10) / 2;
    return mod_targ - mod_cast;
}

// dice roll to dispell is d20 vs 10 + level difference between caster and target + difference in 
// casting stat mods + the level of the spell
int checkDispel(object ob) {
    int roll, level_diff,DC,stat_weight,sp_lvl;

    if(TO->query_caster() == ob->query_caster()) return 1;

    level_diff = (int)ob->query_clevel() - clevel;
    stat_weight = get_stat_mod_difference(ob,caster);
    sp_lvl = (int)ob->query_spell_level();
    DC = 10 + sp_lvl + level_diff + stat_weight;

// +2 bonus vs dispels for shadow adepts, if the dispeller is not also a shadow weave user.
    if(FEATS_D->usable_feat(ob->query_caster(),"shadow adept") && !FEATS_D->usable_feat(TO->query_caster(),"shadow adept")) DC += 2;
    if(FEATS_D->usable_feat(ob->query_caster(),"elusive spellcraft") && !FEATS_D->usable_feat(TO->query_caster(),"elusive spellcraft")) DC += 2;

    roll = roll_dice(1,20);
    if(roll >= DC) return 1;
    else return 0;
}


void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
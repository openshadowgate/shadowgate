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
    set_spell_name("dispel psionics");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS dispel psionics [on TARGET]");
    set_description("Despite the name, dispel psionics will dispel effects created by both psionics and magic, whether it "
"be divine or arcane in nature.  The chance to dispel a particular effect depends upon the ability of the psion versus "
"the ability of the effect's caster.  A psion may manifest this item on a room or on a particular target.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return CASTER->QCN+" casts "+CASTER->QP+" gaze about, and the "+
       "area shimmers briefly with a translucent substance!";
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

    arg = query_arg();

    tell_room(PLACE, "%^BOLD%^%^MAGENTA%^The transluscent sheen fades "+
       "away as "+CASTER->QCN+" completes the power!", CASTER);

    tell_object(CASTER, "%^BOLD%^%^MAGENTA%^The shimmering sheen of "+
       "ectoplasm fades away as you manifest the power!");
    if (targ && !objectp(targ)) {  // if there was a target set but it's gone, end
        dest_effect();
        return;
    }
    if(targ && !CASTER->ok_to_kill(targ)) {  
        dest_effect();
        return;
    }
    if (!targ) {  // now, if there wasn't a target set, do the room
        allinv = deep_inventory(PLACE);
        allinv = target_filter(allinv);
        allinv += ({PLACE});

      } else {
        allinv = deep_inventory(targ);
        allinv += ({targ});
    }

    for (i = 0;i < sizeof(allinv);i++) {
        if (!objectp(allinv[i])) continue;
        if(!CASTER->ok_to_kill(allinv[i])) continue;
        if (allinv[i]->query_property("spelled"))
            dispel(allinv[i]);
    }
    spell_successful();
    dest_effect();
    return 1;
}

void dispel(object ob) {
    object *spells;
    int i;

    if ( !ob->query_property("spelled") )
        return;

    if (pointerp(ob->query_property("spelled")))
        spells = ob->query_property("spelled");
    else
        spells = ({ob->query_property("spelled")});

    if (spells == ({}))
        return;

    for (i = 0;i<sizeof(spells);i++) {
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) {
            tell_object(CASTER, "You sense a force resist your power!");
            continue;
        }
        tell_object(CASTER, "You dispel the "+spells[i]->query_spell_name());
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
    int roll, level_diff,DC,stat_weight,sp_lvl, mylevel;

    if(TO->query_caster() == ob->query_caster()) return 1;

    if(caster->is_class("psywarrior")){
       mylevel = caster->query_guild_level("psywarrior");
    }else{
       mylevel = caster->query_guild_level("psion");
    }
    clevel = (int)TO->query_clevel();
    if(clevel < mylevel){
       clevel = mylevel;
    }
    level_diff = (int)ob->query_clevel() - clevel;

    stat_weight = get_stat_mod_difference(ob,(object)TO->query_caster());

    sp_lvl = (int)ob->query_spell_level();

    DC = 10 + sp_lvl + level_diff + stat_weight;

// +2 bonus vs dispels for shadow adepts, if the dispeller is not also a shadow weave user.
    if(FEATS_D->usable_feat(ob->query_caster(),"shadow adept") && !FEATS_D->usable_feat(TO->query_caster(),"shadow adept")) DC += 2;
    if(FEATS_D->usable_feat(ob->query_caster(),"elusive spellcraft") && !FEATS_D->usable_feat(TO->query_caster(),"elusive spellcraft")) DC += 2;

    roll = roll_dice(1,20);

    if(roll >= DC) { return 1; }
    else { return 0; }
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
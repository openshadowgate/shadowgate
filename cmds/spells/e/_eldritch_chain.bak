// please note: at present touch attacks are not being used on these spells as it makes the class
// too unreliable. It may be possible down the track to balance it with a proper ranged attack
// roll, but current lib doesn't support one well. Can be considered at a later date! N, 1/16.
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit "/cmds/spells/e/_eldritch_blast";

string blasttype, element;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("eldritch chain");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("cast CLASS eldritch chain on TARGET");
    set_description("This is an extension of the core spell-like ability of the warlock - the "
"ability to invoke pure planar energy and hurl it at a foe. Unlike its primary form, the "
"invocation will leap to secondary targets if they are present, more so as the warlock gains in "
"strength. As with the eldritch blast, it can be imbued with various essences.\nSee also: <help "
"blasttype>.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    int damage, targs, i, j;
    string descriptor;
    object *foes, *hits;

    if(!objectp(target)) {
        tell_object(caster,"Your target has eluded you!");
        dest_effect();
        return;
    }
    if (environment(caster) != environment(target)) {
        tell_object(caster,"Your target has eluded you!");
        dest_effect();
        return;
    }
    spell_successful();
    damage = sdamage;
    lifesteal = damage*2/3;
    if(lifesteal < 1) lifesteal = 1;
    lifesteal = lifesteal * -1;
    element = "untyped";
    if(blasttype == "glacial") element = "cold";
    if(blasttype == "brimstone") element = "fire";
    if(blasttype == "lifedrinker") element = "negative energy";
    if(blasttype == "vitriolic") element = "acid";
    descriptor = get_descript();

//    if(caster->Thaco(1,target,0) <= roll_dice(1,20) || blasttype == "vitriolic") {
// we're not using this for now as it makes the class incredibly difficult to balance against the rest.
// we can maybe sub this out for the rangedTouchAC(target) function once it's working pl0x!

      tell_object(caster,"%^MAGENTA%^In a single motion you direct a blast of "+descriptor+" to strike "+target->QCN+" squarely!%^RESET%^");
      tell_object(target,"%^MAGENTA%^"+caster->QCN+" directs a blast of "+descriptor+" to strike you!%^RESET%^");
      tell_room(place,"%^MAGENTA%^"+caster->QCN+" directs a blast of "+descriptor+" to strike "+target->QCN+" squarely!%^RESET%^",({ caster, target }));

      damage_targ(target, target->return_target_limb(), damage, element);
      if(FEATS_D->usable_feat(caster,"hellfire blast")) do_hellfire_damage(target,"full");
      do_secondary(target);
/*    }
    else {
      tell_object(caster,"%^MAGENTA%^In a single motion you direct a blast of "+descriptor+" at "+target->QCN+", but it misses!%^RESET%^");
      tell_object(target,"%^MAGENTA%^"+caster->QCN+" directs a blast of "+descriptor+" at you, but it misses!%^RESET%^");
      tell_room(place,"%^MAGENTA%^"+caster->QCN+" directs a blast of "+descriptor+" at "+target->QCN+", but it misses!%^RESET%^",({ caster, target }));
      dest_effect(); // chain effect ends if you miss someone!
      return;
    } */

// now let's chain to other targets!
    targs = clevel/5; // 1 extra target per 5 levels can be hit
// this was making it do less damage than a fireball. That seems unreasonable! So full damage also to splash targets pl0x.
//    damage = damage/2; // secondary targets take half damage

    foes = all_living(environment(target));
    foes = filter_array(foes, "is_non_immortal",FILTERS_D);
    if (member_array(target,foes) != -1) foes -= ({ target });
    if (member_array(caster,foes) != -1) foes -= ({ caster });
    if(FEATS_D->usable_feat(caster,"perfect caster")) foes = filter_array(foes,"perfect_filter",TO);
    foes = distinct_array(foes);
    hits = ({});

    for(i=0;i<targs;i++) { // picking up an array of potential targets
      if(sizeof(foes)) {
        j = random(sizeof(foes));
        hits += ({ foes[j] });
        foes -= ({ foes[j] });
      }
    }

    for(i=0;i<sizeof(hits);i++) {
        tell_object(hits[i],"%^MAGENTA%^The blast of "+descriptor+" arcs to hit you!%^RESET%^");
        tell_room(place,"%^MAGENTA%^The blast of "+descriptor+" arcs to hit "+hits[i]->QCN+"!%^RESET%^",hits[i]);
        damage_targ(hits[i], hits[i]->return_target_limb(), damage, element);
        do_secondary(hits[i]);
    }
    dest_effect();
}


void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

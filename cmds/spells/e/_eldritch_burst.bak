#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit "/cmds/spells/e/_eldritch_blast";

string blasttype, element;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("eldritch burst");
    set_spell_level(([ "warlock" : 4 ]));
    set_syntax("cast CLASS eldritch burst");
    set_description("This is the pinnacle of the core spell-like ability of the warlock - the "
"ability to invoke pure planar energy and hurl it at a foe. Unlike its primary form, the "
"invocation emits in a burst from the caster, striking any foe within reach. As this is not "
"a ray, no touch attack is required, but foes can attempt a reflex save to avoid part of the "
"damage. As with the eldritch blast, it can be imbued with various essences.\nSee also: <help "
"blasttype>.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_target_required(0);
}

void spell_effect(int prof) {
    int damage, i;
    string descriptor;
    object *attackers;

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

    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    if(!sizeof(attackers)){
        tell_object(caster,"%^MAGENTA%^You unleash a burst of "+descriptor+", but it doesn't hit anything.%^RESET%^");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" unleashes a burst of "+descriptor+", but it doesn't hit anything.%^RESET%^",caster);
        dest_effect();
        return;
    }
    tell_object(caster,"%^MAGENTA%^You unleash a burst of "+descriptor+"!%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" unleashes a burst of "+descriptor+"!%^RESET%^",caster);

    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) continue;

        set_save("reflex");
        if(do_save(attackers[i],0)) {
          if(evade_splash(attackers[i])) continue;
          tell_object(attackers[i],"%^MAGENTA%^You are caught by the edge of the burst!%^RESET%^");
          damage_targ(attackers[i],attackers[i]->return_target_limb(),damage/2,element);
          if(FEATS_D->usable_feat(caster,"hellfire blast")) do_hellfire_damage(attackers[i],"half");
          do_secondary(attackers[i]);
        }
        else {
          tell_object(attackers[i],"%^MAGENTA%^You are struck by the full force of the burst!%^RESET%^");
          damage_targ(attackers[i],attackers[i]->return_target_limb(),damage,element);
          if(FEATS_D->usable_feat(caster,"hellfire blast")) do_hellfire_damage(attackers[i],"full");
          do_secondary(attackers[i]);
        }
    }
    dest_effect();
}


void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

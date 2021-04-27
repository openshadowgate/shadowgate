#include <std.h>
inherit SPELL;

object *mons = ({});

void create() {
    ::create();
    set_spell_name("summon locusts");
    set_spell_level(6);
    set_spell_type("wizard");
    set_spell_sphere("conjuration_summoning");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components( ([
                     "emerald":2
                     ]) );
}

string query_casting_string() {
    return "%^BOLD%^%^GREEN%^"+caster->QCN+" pulls a pair of %^GREEN%^ge%^MAGENTA%^ms%^GREEN%^t%^MAGENTA%^on"
"%^GREEN%^es %^WHITE%^from the base of "+caster->QP+" scepter, letting them fall to the ground.";
}

int preSpell() {
    if (present(caster->query_name()+"locust",place)) {
        tell_object(caster,"You can't summon multiple sets of locusts.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object ob;
    int i;

    tell_object(caster,"%^BOLD%^%^WHITE%^You pull a pair of %^GREEN%^ge%^MAGENTA%^ms%^GREEN%^t%^MAGENTA%^on"
"%^GREEN%^es %^WHITE%^from the base of your scepter, letting them fall to the ground.");
    tell_room(place,"%^BOLD%^%^WHITE%^At a touch from the head of the scepter, they crack open to reveal a "
"swarm of hungry %^BLACK%^locusts%^WHITE%^!");
    for (i=0;i<(random(4)+5);i++) {
      ob = new("/d/avatars/nienne/amulet/locust");
      ob->move(place);
      ob->force_me("protect "+caster->query_name());
      ob->force_me("protect "+caster->query_name());      
      ob->set_property("spelled", ({TO}) );
      ob->set_property("spell_creature", TO);
      ob->set_property("spell", TO);
      ob->set_attack_bonus(clevel/5);
      ob->set_exp(0);
      ob->add_id("summoned locust");
      ob->add_id(caster->query_name()+"locust");
      caster->add_follower(ob);
      mons += ({ob});
    }
    addSpellToCaster();
    call_out("dest_effect",clevel*(prof/25));
}

void dest_effect() {
    int i;
    if(present("summoned locust",environment(caster)))
      tell_room(environment(caster),"%^BOLD%^%^WHITE%^With a whirring of wings, the locusts lift off into the "
"air and scatter!%^RESET%^");
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i])) {
            caster->remove_protector(mons[i]);
            mons[i]->remove();
        }
    }
    ::dest_effect();
}

void reverse_spell(){
    int i;
    spell_effect(100);

    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i])) {
            mons[i]->force_me("scream in rage");
            mons[i]->add_attacker(caster);
        }
    }
   removeSpellFromCaster();
}

int help() {
    write(
@OLI
Spell  : Faithful Phantom Guardians
Level  : 6th Level
Sphere : Summoning
Syntax : cast phantom guardians on <centaurs|bats|soldiers>

This spell creates casting level relative guardians who will guard the caster
blindly.  You have the choice of 3 types: 2 centaurs, 4 soldiers or 8 bats.
These guardians will not be effected by area effect spells.

Material components required: 2 emeralds
OLI
);
    return 1;
}

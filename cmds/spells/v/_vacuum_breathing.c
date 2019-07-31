//fixed name based on bug report ~Circe~ 7/31/19
#include <std.h>

#define WTROB "/d/magic/obj/vacuum_breathob.c"

inherit SPELL;
object breathob;

void create(){
    ::create();
    set_spell_name("vacuum breathing");
    set_spell_level(([ "mage" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS vacuum breathing on TARGET");
    set_description("This spell allows the target to survive in a vacuum for a limited period of time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "bell jar" : 1, ]),
    ]));

    set_helpful_spell(1);
}

int preSpell(){
    if(present("vacuum_breath_ob", target)){
      tell_object(caster, target->QCN+" can already survive a vacuum.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (environment(target)!=place) {
      tell_object(caster,"Your target has left the area!");
      TO->remove();
      return;
    }

    spell_successful();
    tell_room(environment(caster), ""+caster->QCN+" touches "+target->QCN+"'s nose and mouth lightly.", ({caster, target}) );
    tell_object(caster, "You give "+target->QCN+" the ability to survive in a vacuum.");
    tell_object(target, ""+caster->QCN+" gives you the power to survive in a vacuum.");
    breathob = new(WTROB);
    breathob->set_maxtime(500+(5*clevel*prof/100));
    breathob->set_property("spell", TO);
    breathob->set_property("spelled", ({TO}));
    addSpellToCaster();
    breathob->move(target);
}

void dest_effect(){
    tell_object(target, "You feel the power to survive in a vacuum leave you.");
    if(objectp(breathob))
      breathob->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void reverse_spell(){
    spell_effect(-100);
}

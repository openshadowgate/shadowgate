#include <std.h>
inherit SPELL;

int newhp;

void create() {
   ::create();
   set_spell_name("aspect of the bear");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   tell_object(caster,"%^GREEN%^You call upon the aspect of the bear, and feel its endurance strengthening you.");
   tell_room(environment(caster),"%^GREEN%^"+caster->QCN+" seems filled with inner strength, giving "+caster->QO+" a healthy glow.",caster);
   newhp = 8*clevel;
   newhp = newhp - (int)caster->query_max_hp();
   newhp = newhp - (int)caster->query_extra_hp();
   if (newhp < 0) newhp = 0;
   caster->add_extra_hp(newhp);
   caster->add_ac_bonus(2);
   caster->add_saving_bonus("all",2);
   addSpellToCaster();
   spell_successful();
   call_out("dest_effect",clevel*8);
}

void dest_effect() {
   ::dest_effect();
   if (!objectp(TO)) return;
   if (!objectp(caster)) {
     TO->remove();
     return;
   }
   caster->add_extra_hp(-1* newhp);
   if ((int)caster->query_extra_hp() < 0) {
     caster->add_extra_hp(-1 * (int)caster->query_extra_hp());
   }
   caster->add_ac_bonus(-2);
   caster->add_saving_bonus("all",-2);
   caster->remove_property_value("spelled", ({TO}) );
   tell_object(caster,"%^GREEN%^The inner strength fades from you, leaving you feeling normal again.%^RESET%^");
   tell_room(environment(caster),"%^GREEN%^"+caster->QCN+"'s healthy glow fades, leaving "+caster->QO+" looking normal again.%^RESET%^",caster);
   TO->remove();
   return;
}

int help() {
    write(
@OLI
Spell  : Aspect of the Bear
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the bear, giving you the resilience and endurance of the creature.

OLI
);
    return 1;
}

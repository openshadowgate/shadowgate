#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

object caster, place, target;

void create() {
   ::create();
   set_spell_name("aspect of the trees");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   int num;
   ::spell_effect();
   place = PLACE;
   caster = CASTER;
   target = TARGET;
   num = ((int)CLEVEL - roll_dice(1,6));
   tell_room(place,"%^GREEN%^"+caster->QCN+"'s skin becomes hard and barklike, protecting "+caster->QO+" from harm!%^RESET%^",caster);
   tell_object(caster,"%^GREEN%^You call upon the aspect of the trees, and your skin becomes barklike, hardening to protect you from harm!%^RESET%^");
   caster->set_property("spelled",({TO}));
   caster->set_stoneSkinned(num);
   addSpellToCaster();
   return;
}

void dest_effect() {
   if (!objectp(caster)) {
     TO->remove();
     return;
   }
   tell_room(environment(caster),"%^GREEN%^"+caster->QCN+"'s skin loses its rough texture and returns to normal.%^RESET%^",caster);
   tell_object(caster,"%^GREEN%^Your barklike skin loses its rough texture and returns to normal.%^RESET%^");
   caster->set_stoneSkinned(0);
   caster->remove_property_value("spelled", ({TO}) );
   TO->remove();
}

int help() {
    write(
@EndText
Spell  : Aspect of the trees
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the trees, granting you barklike skin that will protect you from blows.

EndText
);
    return 1;
}

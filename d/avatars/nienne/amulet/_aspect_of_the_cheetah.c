#include <std.h>
inherit SPELL;

void create() {
   ::create();
   set_spell_name("aspect of the cheetah");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   tell_room(place,"%^GREEN%^"+caster->QCN+" seems suddenly invigorated, and "+caster->QP+" movements become unnaturally swift!%^RESET%^",caster);
   tell_object(caster, "%^GREEN%^You call upon the aspect of the cheetah, invigorating your body with sudden speed!%^RESET%^");
   caster->set_blinking(clevel - random(4));
   caster->add_stat_bonus("dexterity",1);
   addSpellToCaster();
   spell_successful();
   call_out("test", 5);
}

void test() {
   if (!objectp(TO) || !objectp(caster)) return;
   if(!caster->query_blinking()) {
     TO->dest_effect();
     return;
   }
   call_out("test", 5);
}

void dest_effect() {
    ::dest_effect();
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    tell_object(caster,"%^GREEN%^You feel the burst of speed leave you, returning to your normal self.%^RESET%^");
    tell_room(environment(caster),"%^GREEN%^"+caster->QCN+" seems to slow back down to "+caster->QP+" natural speed.%^RESET%^",caster);
    caster->set_blinking(0);
    remove_call_out("test");
    caster->remove_property_value("spelled", ({TO}) );
    caster->add_stat_bonus("dexterity",-1);
    TO->remove();
    return;
}

int help() {
   write(
@OLI
Spell  : Aspect of the Cheetah
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the cheetah, granting you unnatural grace and swiftness for a time.

OLI
   );
}

#include <priest.h>
inherit SPELL;

void create() {
   ::create();
   set_spell_name("aspect of the waters");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   tell_object(CASTER, "%^GREEN%^You call upon the aspect of the waters, and feel its gentle healing powers fill your body, leaving you feeling refreshed.%^RESET%^");
   tell_room(PLACE,"%^GREEN%^A gentle mist rises around "+YOU+", leaving "+CASTER->QO+" looking refreshed.%^RESET%^",CASTER);
   if((int)CASTER->query_hp() < (int)CASTER->query_max_hp() ){
     CASTER->add_hp((int)CASTER->query_max_hp() - ((int)CASTER->query_hp()));
   }
   CASTER->remove_paralyzed();
   CASTER->set_blind(0);
   CASTER->set_temporary_blind(0);
   CASTER->set_poisoning((-1)*(int)CASTER->query_poisoning());
   dest_effect();
}

void dest_effect() {
   ::dest_effect();
   TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Aspect of the waters
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the waters, healing your wounds and removing ill effects from your person.

HELP
);
   return 1;
}

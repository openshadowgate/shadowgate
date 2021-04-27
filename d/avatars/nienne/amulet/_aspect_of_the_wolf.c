#include <std.h>
#include <priest.h>
inherit SPELL;

int mybonus;

void create() {
   ::create();
   set_spell_name("aspect of the wolf");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   int clevel;
   clevel = CLEVEL;
   mybonus = (clevel/10)+1;
   addSpellToCaster();
   spell_successful();
   tell_room(place,"%^GREEN%^"+caster->QCN+"'s movements become more precise and honed, as if with intense combat prowess!%^RESET%^",caster);
   tell_object(caster, "%^GREEN%^You call upon the aspect of the wolf, and feel your body filled with power!%^RESET%^");
   caster->add_attack_bonus(mybonus);
   caster->add_damage_bonus(mybonus);
   caster->add_saving_bonus("all",2);
   call_out("dest_effect",clevel*8);
}

void dest_effect(){
   ::dest_effect();
   if (!objectp(TO)) return;
   if (!objectp(caster)) {
     TO->remove();
     return;
   }
   caster->add_attack_bonus(-1 * mybonus);
   caster->add_damage_bonus(-1 * mybonus);
   caster->add_saving_bonus("all",-2);
   tell_room(place,"%^GREEN%^The accuracy of "+caster->QCN+"'s movements fades, leaving "+caster->QS+" normal again.%^RESET%^", caster);
   tell_object(caster,"%^GREEN%^The aspect fades from you, leaving you feeling normal once again.%^RESET%^");
   TO->remove();
}

int help() {
    write(
@OLI
Spell  : Aspect of the wolf
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the wolf, granting you the animal's strength and skill in combat.

OLI
);
    return 1;
}

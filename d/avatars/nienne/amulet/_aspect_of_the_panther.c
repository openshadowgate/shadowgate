#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

object invisob, caster, place;

void create() {
   ::create();
   set_spell_name("aspect of the panther");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

spell_effect(int prof) {
   caster = CASTER;
   place = PLACE;
   target = TARGET;
   if (!target) target=caster;
   tell_object(caster,"%^GREEN%^You call upon the aspect of the panther, and become a shadowy silhouette of your former self.%^RESET%^");
   tell_room(place,"%^GREEN%^"+caster->QCN+" seems to fade before your eyes, becoming a shadowy silhouette!%^RESET%^",caster);
   call_out("targ_vanish",2);
}

void targ_vanish() {
   spell_successful();
   invisob=new("/d/avatars/nienne/amulet/invisobcl.c");
   invisob->set_property("spell",TO);
   invisob->set_property("spelled", ({TO}) );
   invisob->move_is_ok(1);
   invisob->move(target);
   invisob->move_is_ok(0);
   addSpellToCaster();
   return;
}

void dest_effect() {
   ::dest_effect();
   invisob->show_up();
   TO->remove();
}

int help() {
   write(
@HELP
Spell  : Aspect of the panther
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the cheetah, granting you the stealth of the creature for a time.

HELP
);
    return 1;
}

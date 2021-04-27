#include <spell.h>
#include <magic.h>
inherit SPELL;

object oldenv, *conceal;
int i, num = 0;

void dest_effect();
object *invisobs();
void env_change();
void see_room();
void see_changes();

void create() {
   ::create();
   set_spell_name("aspect of the owl");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   int bonus = prof;
   caster=CASTER;
   oldenv=environment(caster);
   spell_successful();
   tell_room(environment(caster),"%^GREEN%^"+caster->QCN+"'s eyes take on an intense %^YELLOW%^golden glow%^RESET%^%^GREEN%^.%^RESET%^",caster);
    tell_object(caster,"%^GREEN%^You call upon the aspect of the owl, and your vision sharpens intensely!%^RESET%^");
   caster->set_detecting_invis(1);
   addSpellToCaster();
   call_out("dest_effect", clevel * ROUND_LENGTH);
}

void dest_effect() {
   ::dest_effect();
   if (caster) {
     tell_object(caster,"%^GREEN%^Your sharpened vision gently fades back to its normal acuteness.%^RESET%^");
     tell_room(environment(caster),"%^GREEN%^"+caster->QCN+"'s %^YELLOW%^glowing golden %^RESET%^%^GREEN%^eyes return to their usual "
+(string)caster->query_eye_color()+" hue.",caster);
     caster->set_detecting_invis(0);
   }
   TO->remove();
}

int help() {
    write(
@EndText
Spell  : Aspect of the owl
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the owl, granting you supernaturally sharpened vision.

EndText
);
    return 1;
}

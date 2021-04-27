#include <priest.h>
inherit SPELL;

void create() {
   ::create();
   set_spell_name("aspect of the winds");
   set_spell_level(5);
   set_spell_type("priest");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"ranger"}));
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" invokes the wilderness to aid "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   string where;
   object mywhere;
   where = "/d/magic/temples/mielikki";
   mywhere = find_object_or_load(where);

   if (environment(CASTER)->query_property("no teleport")) {
     tell_object(CASTER,"%^GREEN%^Your spell seems not to work here.%^RESET%^");
     dest_effect();
     return;
   }
   tell_object(CASTER, "%^GREEN%^You call upon the aspect of the winds, and they pick up around you, lifting you in a whirl of motion!%^RESET%^");
   tell_room(PLACE, "%^GREEN%^Wild winds pick up around you, lifting and carrying "+YOU+" away!%^RESET%^", ({ CASTER}));
    tell_object(CASTER, "%^GREEN%^When the gusts settle again, you find yourself safe within the sanctuary of the Mielikkian temple.%^RESET%^");
    tell_room(where, "%^GREEN%^Wild winds pick up around you, and when they dissipate they leave "+YOU+" standing before you.%^RESET%^",CASTER);
    CASTER->move_player(where);
    CASTER->set_casting(0);
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Aspect of the winds
Level  : 5th Level
Sphere : Alteration

This spell invokes the essence of the winds, carrying you back to the sanctuary of Mielikki.

HELP
);
    return 1;
}

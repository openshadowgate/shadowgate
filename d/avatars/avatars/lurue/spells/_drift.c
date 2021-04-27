#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

object invisob, caster, place;

create() {
    ::create();
    set_spell_name("drift");
    set_spell_level(1);
    set_spell_type("priest");
    set_spell_sphere("illusion");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" pulls the cloak tight around "+caster->QO+".";
}

spell_effect(int prof) {
    caster = CASTER;
    place = PLACE;
    target = TARGET;
    if (!target)
        target=caster;
    tell_object(caster,"%^GREEN%^You pull the cloak tight around you, and the silken leaves swirl about and "
"split apart.%^RESET%^");
    tell_room(place,"%^GREEN%^The silken leaves of "+caster->QCN+"'s cloak ripple and swirl as they are drawn "
"close around "+caster->QO+".",caster);
    call_out("targ_vanish",2);
}

void targ_vanish() {
    spell_successful();
    tell_object(caster,"%^GREEN%^The leaves scatter and you feel your very essence scattering with them, "
"unseen and unnoticed like a whisp on the air.%^RESET%^");
    tell_room(place,"%^GREEN%^When the leaves drift apart again "+caster->QCN+" is gone!",caster);
    invisob=new("/d/magic/obj/invisobcl.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(target);
    invisob->move_is_ok(0);
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
Spell  : Drift
Level  : 1st Level
Sphere : Illusion
Syntax : chant drift

If you are outdoors, this spell will allow you to hide
yourself in the land around you magically.
HELP
);
    return 1;
}

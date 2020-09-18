#include <std.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("nightmare");
    set_spell_level(([ "mage" : 5, "bard":5, "psion":5]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS nightmare on TARGET");
    set_damage_desc("mental, fatigue for clevel / 4 + 1  rounds");
    set_description("The nightmare prevents restful sleep and causes target to become fatigued for a very long period of time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " makes a few passes in the air, whispering in dread undertones.%^RESET%^";
}

spell_effect()
{

    if (!do_save(target, 0)) {
        if (mind_immunity_damage(target, "default")) {
            spell_successful();
            dest_effect();
            return;
        }
        "/std/effect/status/fatigued"->apply_effect(target, clevel / 4 + 1);
    }

    damage_targ(target, target->return_target_limb(), sdamage, "mental");

    tell_object(target, "%^BLUE%^A heavy nightmarish vision descends upon you as " + caster->QCN + " completes the spell.");
    tell_room(ENV(target), "%^BLUE%^" + target->QCN + " shudders and staggers as feeling of dread swipes by the area.", target);

}

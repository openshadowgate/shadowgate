#include <std.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("detect thoughts");
    set_spell_level(([ "bard":2, "inquisitor":2, "mage":2]));
    set_spell_sphere("divination");
    set_damage_desc("indicates presence of telepathic communication in the area");
    set_syntax("cast CLASS detect thoughts");
    set_description("This spell allows you to detect who is communicating with whom in the area. This detection chance might be, however identified and if difference between listener's and target's intelligence scores is too high it will leave listener stunned. This version of the spell doesn't allow you to discern what is being spoken.");

    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

spell_effect()
{
    tell_object(caster,"%^CYAN%^You quickly touch your temples, attuning yourself to detect presence of telepathic communication.");
    tell_room(place, "%^CYAN%^" + caster->QCN + " quickly touches his temples.");

    spell_successful();
    caster->set_property("spelled", ({TO}) );
    caster->set_property("detecting_thoughts", clevel);
    addSpellToCaster();
    call_out("dest_effect", ROUND_LENGTH * (clevel / 10 + roll_dice(1, 6)));
}

dest_effect()
{
    if (objectp(caster)) {
        if (caster->query_property("detecting_thoughts")) {
            caster->remove_property("detecting_thoughts");
            tell_object(caster,"%^CYAN%^You sense you loose your grasp on presence of through.");
        }
    }

    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

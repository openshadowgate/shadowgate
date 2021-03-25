#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("celestial healing");
    set_spell_level(([ "mage" : 1, "cleric" : 1, "magus" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS celestial healing [on TARGET]");
    set_damage_desc("fast healing 1");
    set_description("You anoint a wounded creature with the blood of an outsider with the good subtype (such as an angel) or holy water, giving it faster healing. For the duration of the spell you'll have a good aura.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^ORANGE%^"+caster->QCN+" %^BOLD%^%^ORANGE%^spells an %^ORANGE%^i%^WHITE%^n%^ORANGE%^f%^WHITE%^ernal %^WHITE%^inc%^ORANGE%^a%^WHITE%^nt%^ORANGE%^a%^ORANGE%^t%^WHITE%^ion.%^RESET%^
";
}

int preSpell()
{
    if (!target) {
        target = caster;
    }

    if (target->query_property("fast_healing_spell") || target->query_property("hidden alignment")) {
        tell_object(caster, "%^BOLD%^%^WHITE%^You feel your spell repelled...");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    if (!target) {
        target = caster;
    }

    if (!objectp(target)) {
        TO->remove();
        return;
    }
    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    tell_room(place, "%^ORANGE%^An %^ORANGE%^i%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^ustri%^RESET%^%^ORANGE%^o%^ORANGE%^u%^BOLD%^%^ORANGE%^s %^ORANGE%^ha%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^ shines above " + target->QCN + "' head.", target);

    {
        int duration = clevel * ROUND_LENGTH * 12;

        tell_object(target, "%^ORANGE%^An %^ORANGE%^i%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^ustri%^RESET%^%^ORANGE%^o%^ORANGE%^u%^BOLD%^%^ORANGE%^s %^ORANGE%^ha%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^ shines above your head.");

        target->set_property("spelled", ({ TO }));
        target->set_property("fast healing", 1);
        target->set_property("fast_healing_spell", 1);
        target->set_property("hidden alignment", 4);
        spell_successful();
        addSpellToCaster();
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }

}

void dest_effect()
{
    if (objectp(target)) {
        tell_object(target, "%^BOLD%^%^ORANGE%^The celestial light abandons your blood.%^RESET%^");
        target->remove_property_value("spelled", ({ TO }));
        target->set_property("fast healing", -1);
        target->remove_property("fast_healing_spell");
        target->remove_property("hidden alignment");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

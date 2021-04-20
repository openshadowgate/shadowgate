#include <std.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("consecrate");
    set_spell_level((["paladin":1, "cleric":1, "inquisitor":2]));
    set_spell_sphere("invocation_evocation");
    set_damage_desc("clevel / 10 + 1 to attack and damage bonus, saves, to all present undead");
    set_syntax("cast CLASS consecrate");
    set_description("This spell imbues every unliving with positive energy, giving them long lasting penalties to their abilities.");
    evil_spell(1);
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^BOLD%^%^ORANGE%^As " + caster->QCN + " chants in low undertones, the celestial light infuses the area.";
}

void spell_effect()
{
    object * undeads, peep;
    int bonus = clevel / 10 + 1;

    undeads = all_living(place);
    undeads = filter_array(undeads, (:$1->is_undead():));
    undeads = filter_array(undeads, (:!$1->query_property("consecrated"):));

    spell_successful();

    if (!sizeof(undeads)) {
        tell_object(caster,"%^ORANGE%^The energy disperses and affects noone.");
        tell_room(place,"%^ORANGE%^The energy around " + caster->QCN + " disperses.", caster);
        dest_effect();
        return 1;
    }

    undeads->add_saving_bonus("all",bonus );
    undeads->add_attack_bonus(bonus);
    undeads->add_damage_bonus(bonus);
    undeads->set_property("consecrated", 1);

    tell_object(caster,"%^ORANGE%^The power of life washes over the area, infusing present undead.");
    tell_room(place,"%^ORANGE%^Luminous waves of light disperse from " + caster->QCN + "'s direction.", caster);
    foreach(peep in undeads) {
        tell_object(peep,"%^BOLD%^%^ORANGE%^You feel weakened.");
    }
}

#include <std.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("desecrate");
    set_spell_level((["paladin":1, "cleric":1, "inquisitor":2]));
    set_spell_sphere("invocation_evocation");
    set_damage_desc("clevel / 10 + 1 to attack and damage bonus, saves, to all present undead");
    set_syntax("cast CLASS desecrate");
    set_description("This spell imbues every unliving with negative energy, giving them long lasting bonuses to their abilities.");
    evil_spell(1);
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^As " + caster->QCN + " chants in low undertones, the feeling of dread infuses the area.";
}

void spell_effect()
{
    object * undeads, peep;
    int bonus = clevel / 10 + 1;

    undeads = all_living(place);
    undeads = filter_array(undeads, (:$1->is_undead():));
    undeads = filter_array(undeads, (:!$1->query_property("desecrated"):));

    spell_successful();

    if (!sizeof(undeads)) {
        tell_object(caster,"%^BLUE%^The energy disperses and affects noone.");
        tell_room(place,"%^BLUE%^The energy around " + caster->QCN + " disperses.", caster);
        dest_effect();
        return 1;
    }

    undeads->add_saving_bonus("all",bonus );
    undeads->add_attack_bonus(bonus);
    undeads->add_damage_bonus(bonus);
    undeads->set_property("desecrated", 1);

    tell_object(caster,"%^BLUE%^The power of death washes over the area, infusing present undead.");
    tell_room(place,"%^BLUE%^Dreadful waves of cold disperse from " + caster->QCN + "'s direction.", caster);
    foreach(peep in undeads) {
        tell_object(peep,"%^BOLD%^%^BLUE%^You feel empowered.");
    }
}

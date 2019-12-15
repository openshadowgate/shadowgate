// for fey'ri race & later other class use. N, 1/14.
#include <priest.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("alter self");
    set_spell_level(([ "bard" : 2, "psion" : 2, "psywarrior": 2, "assassin" : 1, "mage" : 2, "druid" : 1, "inquisitor":1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS alter self [RACE]");
    set_description("%^RESET%^This spell allows the caster to make minor changes to their body. These are usually sufficient changes that they become unrecognizable even to those they are familiar with. It does not allow for such drastic changes as body size or overall shape.

This spell does not alter details on your scoresheet (eyes, hair) but the caster may describe their new form and features differently to these if they so choose. They must still maintain their overall body shape, height and weitght.

You can only have one altered form with this spell - repeat uses do not grant additional different shapeshifts, but instead return you to the same secondary form. Adjective, description, speech, messages etc will be remembered across castings, so they will only need to be set once in your alternative form. Players will be able to recognise your 'other self' as a unique entity, separate from your usual self.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
    set_helpful_spell(1);
    set_arg_needed(1);
}

int preSpell()
{
    object shape;
    if(objectp(shape = caster->query_property("shapeshifted")) || objectp(shape = caster->query_property("altered")))
    {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
	return "%^BOLD%^%^WHITE%^"+YOU+" closes "+MINE+" eyes and concentrates deeply.";
}

void spell_effect(int prof)
{
    string raceto = arg;
    if(member_array(raceto,RACE_D->query_races())==-1)
        raceto = caster->query("race");
    if (!objectp(caster) || !userp(caster)) { TO->remove(); return; }
    new("/std/races/shapeshifted_races/spell_alter_self.c")->init_shape(caster,raceto);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    object shape;
    if(objectp(caster))
    {
        if(objectp(shape = caster->query_property("altered"))) shape->reverse_shape(caster);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

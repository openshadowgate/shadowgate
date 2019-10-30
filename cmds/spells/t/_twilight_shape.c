#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

string *valid_forms()
{
    return ({"bat","wolf",});
}

void create()
{
    ::create();
    set_spell_name("twilight shape");
    set_spell_level(([ "innate" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS twilight shape on bat|wolf");
    set_description("With this spell a vampire can change her body into a bat or a wolf. Bat is a tiny flying creature incapable of combat, while wolf form provides a vampire with the same strenghts as druidic wolf form. In addition, bat form can use <wing> command.

%^BOLD%^%^RED%^N.B.%^RESET%^ You can set alternative description, speech string and adjective for these forms.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    object shape;
    if(objectp(shape = caster->query_property("shapeshifted")) ||
       objectp(shape = caster->query_property("altered")))
    {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
    }
    if(member_array(arg,valid_forms())==-1)
    {
        tell_object(caster,"Invalid form, valid forms are: "+implode(valid_forms(),", "));
        return;
    }
    return 1;
}

void spell_effect(int prof)
{
    object shape;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    new("/std/races/shapeshifted_races/vampire_"+arg+".c")->init_shape(caster,arg);

    shape = caster->query_property("shapeshifted");
    bonus = clevel/4+1;
    caster->add_attack_bonus(bonus);
    caster->add_damage_bonus(bonus);
    caster->set_property("dance-of-cuts",1); //Full BAB
    spell_successful();

    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
}

void dest_effect()
{
    object shape;
	if(objectp(caster))
    {
        caster->add_attack_bonus(-bonus);
        caster->add_damage_bonus(-bonus);
        caster->set_property("dance-of-cuts",-1);
        if(objectp(shape = caster->query_property("shapeshifted"))) shape->reverse_shape(caster);
	}
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

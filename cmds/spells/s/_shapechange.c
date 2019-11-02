#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

string *valid_forms()
{
    return ({"dragon","demon","golem"});
}

void create()
{
    ::create();
    set_spell_name("shapechange");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("alteration");
    set_sorc_bloodlines(({"aberrant","fey"}));
    set_syntax("cast CLASS shapechange on demon|golem|dragon");
    set_description("With this spell you transform into one of several fearsome creatures. In the new form you won't be able to access your inventory, but you will posses mighty melee abilities. The potency of the form will grow with your power, but it won't benefit from transformation spell. In addition, demon and dragon forms can use <wing> command to travel.

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
    new("/std/races/shapeshifted_races/mage_"+arg+".c")->init_shape(caster,arg);

    shape = caster->query_property("shapeshifted");
    shape->set_clevel(clevel);
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

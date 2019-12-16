#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

string *valid_forms()
{
    return ({"fire","air","earth","water"});
}

mapping elementmap;
elementmap = ([
                  "fire":"%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h",
                  "air":"%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^r",
                  "earth":"%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h",
                  "water":"%^BOLD%^%^BLUE%^w%^CYAN%^a%^WHITE%^t%^CYAN%^e%^BLUE%^r"
                  ]);

void create()
{
    ::create();
    set_spell_name("elemental body i");
    set_spell_level(([ "mage" : 4]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS shapechange on demon|golem|dragon");
    set_description("

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
    new("/std/races/shapeshifted_races/mage_elemental.c")->init_shape(caster,"");

    tell_object(FPL("ilmarinen"),":"+identify(shape));

    shape = caster->query_property("shapeshifted");

    tell_object(FPL("ilmarinen"),":"+identify(shape));
    shape->set_clevel(clevel);
    bonus = clevel/4+1;
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
        caster->set_property("dance-of-cuts",-1);
        if(objectp(shape = caster->query_property("shapeshifted"))) shape->reverse_shape(caster);
	}
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

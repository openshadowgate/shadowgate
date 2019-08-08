#include <spell.h>
#include <daemons.h>
inherit SPELL;

string *valid_forms()
{
    return ({"dragon"});
}

void create()
{
    ::create();
    set_spell_name("shapechange");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS shapechange on balor|fire_giant|iron_golem|red_dragon");
    set_description("IN TESTING");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
      object shape;
      if(objectp(shape = caster->query_property("shapeshifted")) ||
         objectp(shape = caster->query_property("altered")))
      {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
      }
      return 1;
}

void spell_effect(int prof)
{
    object shape;
    int bonus;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    new("/std/races/shapeshifted_races/mage_dragon.c")->init_shape(caster,"dragon");

    shape = caster->query_property("shapeshifted");
    bonus = clevel/4+1;
    shape->set_clevel(clevel);
    spell_successful();

    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
}



void dest_effect()
{
    object shape;
	if(objectp(caster))
    {
        if(objectp(shape = caster->query_property("shapeshifted"))) shape->reverse_shape(caster);
	}
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

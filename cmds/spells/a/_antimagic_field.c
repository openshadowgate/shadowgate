#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("antimagic field");
    set_spell_level(([ "cleric" : 8, "mage" : 8 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS antimagic field");
    set_damage_desc("triggers wild magic in the area");
    set_description("An invisible barrier is placed in the area. Any spell cast must be cast at a greater strength or it fizzle out. Any ongoing spells will cause no damage if their power is lower that of the caster. ");
}

int preSpell()
{
    if(place->query_property("antimagic field"))
    {
      tell_object(caster,"You feel your attempt to cast the spell repelled.");
      return 0;
   }
   return 1;
}

void spell_effect()
{
    tell_room(place,"%^RESET%^%^CYAN%^You feel an emptiness on your soul, as if something is missing from the world.%^RESET%^");

    if(place->query_property("antimagic field")<(clevel-1))
        place->remove_property("antimagic field");

    place->set_property("antimagic field", clevel-1);

    spell_successful();
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();

    call_out("dest_effect",(clevel/4+1)*ROUND_LENGTH);

    call_out("notify_effect",ROUND_LENGTH*2);
}

void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place,"%^BOLD%^%^CYAN%^The magic returns to the area.");
        place->remove_property("antimagic field");
    }
    ::dest_effect();
    return;
}

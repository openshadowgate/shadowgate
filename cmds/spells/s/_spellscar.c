#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("ruin");
    set_spell_level(([ "cleric" : 8, "mage" : 8 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS spellscar");
    set_damage_desc("triggers wild magic in the area");
    set_description("Within the area you choose to affect everything looses its hue. Periodically ripples of vibrant color wriggle through the place. Within this place, spell-like abilities will automatically trigger a wild magic effect.");
}

int preSpell()
{
    if(ENV(caster)->query_property("wild magic"))
    {
      tell_object(caster,"You feel your attempt to cast the spell repelled.");
      return 0;
   }
   return 1;
}

int spell_effect()
{
    tell_room(place,"%^RESET%^%^WHITE%^All colors in the area suddenly turn mute.%^RESET%^");

    EETO->set_property("wild magic", clevel);
    EETO->set_property("wild magic affect", ({"random", "random level", 0}));

    spell_successful();
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();

    call_out("dest_effect",30 + (clevel*10));

    return 1;
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(place))
    {
        dest_effect();
        return;
    }
    if(!random(3))
        message("info", "%^RESET%^%^CYAN%^The colors suddenly turn %^BOLD%^%^CYAN%^v%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^ and %^BOLD%^%^CYAN%^saturat%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^d%^RESET%^%^CYAN%^!", nearbyRoom(place,2));
    environment(CASTER)->addObjectToCombatCycle(TO,1);
}

void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place,"%^RESET%^%^WHITE%^The area regains its colors");
        place->remove_property("wild magic");
        place->remove_property("wild magic affect");
    }
    ::dest_effect();
    return;
}

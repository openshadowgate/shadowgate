#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("kiss of feywild");
    set_spell_level(([ "druid" : 4, "bard" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS kiss of feywild [on TARGET]");
    set_damage_desc("increased max hp points on living");
    set_description("Lo, Their Endless Host, the Harbingers of Life, Mercy and Kindness Followed Where'er She Walked, Where Her Court Will be Held.");
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^GREEN%^With %^CYAN%^b%^BOLD%^ou%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^%^CYAN%^l%^BOLD%^es%^RESET%^%^CYAN%^s %^MAGENTA%^j%^BOLD%^o%^RESET%^%^MAGENTA%^y %^GREEN%^a song of l%^BOLD%^if%^RESET%^%^GREEN%^e is sang.%^WHITE%^";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("spell_bonus_hp") &&
       !target->is_undead())
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
        return 0;
    }
    return 1;
}

void spell_effect()
{
    if(!target)
        target = caster;

    if(!objectp(target))
    {
        TO->remove();
        return;
    }
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    bonus = 2*clevel;
    tell_room(place,"%^BOLD%^%^GREEN%^A song of life embraces "+target->QCN+"'s body.");
    if(target->is_undead())
    {
        tell_object(target,"%^BOLD%^%^BLACK%^BUT JOY IS %^WHITE%^NOT%^BLACK%^ YOUR WAY%^RESET%^");
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...%^RESET%^");
        TO->remove();
    }
    else
    {
        tell_object(target,"%^BOLD%^%^GREEN%^You feel more healthy and joyful.");
        target->add_max_hp_bonus(bonus);
        target->set_property("spell_bonus_hp",1);
        target->set_property("spelled",({TO}));
    }

    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
       target->add_max_hp_bonus(-bonus);
       target->remove_property_value("spelled", ({TO}) );
       target->remove_property("spell_bonus_hp");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

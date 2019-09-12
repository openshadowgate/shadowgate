#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("kiss of the feywild");
    set_spell_level(([ "druid" : 4, "bard" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS kiss of the feywild [on TARGET]");
    set_damage_desc("increased max hp points on living, decreases on undead");
    set_description("Lo, Their Endless Host, the Harbingers of Life, Mercy and Kindness Followed Where'er She Walked, Where Her Court Will be Held.");
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^GREEN%^W%^CYAN%^i%^GREEN%^th %^RESET%^%^GREEN%^b%^MAGENTA%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^n%^BOLD%^d%^CYAN%^l%^GREEN%^es%^RESET%^%^GREEN%^s %^BOLD%^%^MAGENTA%^j%^CYAN%^o%^MAGENTA%^y %^GREEN%^a %^RESET%^%^CYAN%^s%^BOLD%^%^GREEN%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^GREEN%^g is s%^CYAN%^a%^RESET%^%^CYAN%^n%^BOLD%^%^GREEN%^g.%^RESET%^";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("spell_bonus_hp"))
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

    tell_object(caster,"%^BOLD%^%^GREEN%^A song of life embraces "+target->QCN+"'s body.");
    tell_object(target,"%^BOLD%^%^GREEN%^Joy, joy fills your body.");

    bonus = 4*clevel;
    if(target->is_undead())
    {
        tell_object(target,"%^BOLD%^%^BLACK%^BUT JOY IS NOT OUR WAY%^RESET%^");
        target->add_max_hp_bonus(-bonus);
        spell_kill(target,caster);
    }
    else
        target->add_max_hp_bonus(bonus);
    target->set_property("spelled",({TO}));
    target->set_property("spell_bonus_hp",1);
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

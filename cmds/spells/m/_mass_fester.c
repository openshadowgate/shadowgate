#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

object * atttracker = ({});

void create()
{
    ::create();
    set_spell_name("mass fester");
    set_spell_level(([ "inquisitor" : 6 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS mass fester");
    set_damage_desc("resistance to healing spells");
    set_description("Necrotic energy permeates every attacker, blocking some of energy flow, impeding their healing abilities.");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^MAGENTA%^"+caster->QCN+" proclaims and incantation, darkness forms behind "+caster->QO+".";
}

void spell_effect()
{
    object * attackers;

    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    tell_room(place,"%^MAGENTA%^You watch as tendrils of darkness hit everyone attacking "+caster->QCN+".",({caster}));
    tell_object(caster,"%^MAGENTA%^Tendrils of darkness caress your enemies.");

    lower = sdamage;

    foreach(target in attackers)
    {
        if (target->query_property("fester"))
            continue;

        tell_object(target,"%^MAGENTA%^You feel cold as tendrils of darkness released by "+caster->QCN+" reach you.");
        atttracker+=({target});

        target->set_property("fester",lower / 2);
        target->set_property("spelled", ({TO}) );
    }
    tell_room(place,"%^MAGENTA%^The place gets a little cold...");

    addSpellToCaster();
    call_out("dest_effect",(clevel / 12 + 1)*ROUND_LENGTH,lower);
}

void dest_effect()
{
    foreach(target in atttracker)
    {
        if(objectp(target))
        {
            tell_object(target,"%^ORANGE%^The air grows warmer as your ability to heal returns.");
            target->remove_property("fester");
        }
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

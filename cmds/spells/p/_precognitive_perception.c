#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("precognitive perception");
    set_spell_level(([ "mage" : 4, "bard" : 4 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS precognitive perception on TARGET");
    set_damage_desc("half of clevel perception skill");
    set_description("You share some insigts into the future with target, allowing them to better perceive the surroundings.");
    set_arg_needed();
	set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;
    if(target->query_property("precognitive perception"))
    {
        tell_object(caster,"The target is already under the influence of similar effect");
    }
    return 1;
}

spell_effect()
{
    if(!target)
        target = caster;

    if(!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    spell_successful();

    tell_room(place,"%^CYAN%^"+caster->QCN+" with a swift chant touches "+target->QCN+"'s eyes.%^RESET%^");

    bonus=clevel/2+1;
    target->add_skill_bonus("stealth",bonus);
    target->set_property("spelled", ({TO}) );
    target->set_property("precognitive perception",1);
    addSpellToCaster();
    call_out("dest_effect",ROUND_LENGTH*clevel*3);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("stealth",-bonus);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^CYAN%^The precognitive insights retreat.%^RESET%^");
        target->remove_property("precognitive perception");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

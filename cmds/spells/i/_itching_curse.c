#include <std.h>
#include <spell.h>
#include <magic.h>
#include <skills.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("itching curse");
    set_spell_level(([ "paladin" : 1, "bard" : 1, "druid" : 1, "inquisitor" : 1, "mage" : 1 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS itching curse on TARGET");
    set_damage_desc("reduced skills, attack bonus, saves by 1 point");
    set_description("You curse someone with itching curse. Annoying! This spell must be evil.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

int preSpell()
{
    if(target->query_property("itching_curse"))
    {
        tell_object(caster,"The target is already itchy.");
        return 0;
    }
    return 1;
}

void spell_effect()
{
    int i;

    tell_object(caster,"%^GREEN%^You extend your hand and proclaim an itching curse on "+target->QCN);
    tell_room(place,"%^GREEN%^"+caster->QCN+" points with their hand at "+target->QCN+"%^RESET%^",({target,caster}));
    tell_object(target,"%^GREEN%^You feel very itchy after "+caster->QCN+" proclaims a curse.%^RESET%^");

    if(do_save(target,0))
    {
        tell_object(target,"%^GREEN%^You concentrate and ignore effects of the itchy curse.%^RESET%^");
        tell_object(caster,"%^GREEN%^"+target->QCN+" shakes the curse off.%^RESET%^");
        ::dest_effect();
        TO->remove();
        return;
    }

    call_out("dest_effect",(clevel+5)*ROUND_LENGTH);
    call_out("itch_itch",ROUND_LENGTH);

    for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],-1);
    target->add_attack_bonus(-1);
    target->add_saving_bonus("all",-1);

    target->set_property("spelled", ({TO}) ); //Makes the curse dispellable
    addSpellToCaster();
    spell_successful();

}

void itch_itch()
{
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    tell_object(target,"%^GREEN%^Unbearable itching distracts you.%^RESET%^");
    call_out("itch_itch",ROUND_LENGTH*3);
}

void dest_effect()
{
    int i;

    remove_call_out("itch_itch");
    if(objectp(target))
    {
        tell_object(target, "%^GREEN%^Annoying itch finally fades.%^RESET%^");
        target->remove_property("itching_curse");
        target->remove_property_value("spelled", ({TO}) );
        for(i=0;i<sizeof(CORE_SKILLS);i++)
            target->add_skill_bonus(CORE_SKILLS[i],1);
        target->add_attack_bonus(1);
        target->add_saving_bonus("all",1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("lend judgement");
    set_spell_level(([ "inquisitor" : 1,]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS lend judgement on TARGET");
    set_description("You create a conduit of divine knowledge and outrage between you and an ally. That ally gains the benefit of the first of your active judgements (as do you) when you activate them.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_target_required(1);
}

int preSpell()
{
    if(target==caster)
    {
        tell_object(caster,"You already benefint from own judgements!");
        return 0;
    }
    if(caster->query_property("lend_judgement"))
    {
        tell_object(caster,"You're already lending judgement!");
        return 0;
    }
    if(caster->query_property("lended_judgement"))
    {
        tell_object(caster,"They are already benefiting from lend judgement!");
        return 0;
    }
    return 1;
}

spell_effect()
{
    if(!objectp(target))
    {
        tell_object(caster,"Your target no longer exists!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^RED%^You concentrate and engulf "+target->QCN+" in energy of your zeal!");
    tell_object(target,"%^RED%^You feel more powerful as "+caster->QCN+" shares zeal with you.");

    target->set_property("lended_judgement",1);
    caster->set_property("lend_judgement",target);
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
    call_out("dest_effect",ROUND_LENGTH*(clevel+1)*6);
}

dest_effect()
{
    object controller;

    if(objectp(caster))
    {
        caster->remove_property("lend_judgement");
        if(present("judgement_obj",caster))
        {
            controller = present("judgement_obj",caster);
            controller->activate_judgements(controller->query_active_judgements());
        }
        tell_object(caster,"%^RED%^You are no longer lending judgement!");
    }
    if(objectp(target))
        target->remove_property("lended_judgement");

    ::dest_effect();
}

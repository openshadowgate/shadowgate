#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int size;

void create() 
{
    ::create();
    set_spell_name("enlarge person");
    set_spell_level(([ "mage" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS enlarge person [on TARGET]");
    set_description("When this spell is cast, humanoid caster will grow twice in size. This spell will turn halflings into humans, humans into firbolgs, and firbolgs into mountains.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


void spell_effect(int prof) 
{
    if(!target)
        target = caster;
    
    if (target->query_property("enlarged")) 
    {
        tell_object(caster,"The spell is repelled by its own magic.");
        TO->remove();
    }

    if(target->query_size_bonus())
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
    }
    
    spell_successful();

    tell_object(target,"%^YELLOW%^You grow twice in size!");
    tell_room(place,"%^YELLOW%^"+target->QCN+" grows twice in size!", target);

    target->set_property("added short",({"%^YELLOW%^ (gigantic)%^RESET%^"}));
    target->set_size_bonus(1);
    target->set_property("spelled", ({TO}) );
    target->set_property("enlarged",1);
    call_out("dest_effect",ROUND_LENGTH*clevel);
    addSpellToCaster();
}


void dest_effect() 
{    
    if(objectp(target)) 
    {
        target->set_size_bonus(0);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^YELLOW%^You shrink back to normal!");
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+" shrinks back to normal size.", target );
        target->remove_property("added short",({"%^YELLOW%^ (gigantic)%^RESET%^"}));
        target->remove_property("enlarged");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


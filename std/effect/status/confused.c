#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

#define CONFUSION "/std/magic/confusion"

/**
 * Confusion is always spelled and requires a caster!
 */

inherit STATUS;

int counter;

object caster;

void create()
{
    ::create();
    set_name("effect_confused");
}

void status_effect()
{
    int i;
    if(target->query_property("effect_confused"))
        return;

    target->set_property("effect_confused",1);
    if(objectp(query_param()))
        caster = query_param();

    counter = duration;
    maintain_confusion();
}

void maintain_confusion()
{
    if(!objectp(caster)||!objectp(target))
        dest_effect();

    if(counter<0)
        dest_effect();

    CONFUSION->confuse(caster,target);
    call_out("maintain_confusion",ROUND_LENGTH);
    counter--;
}

void dest_effect()
{
    int i;
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^You are no longer confused.%^RESET%^");
        target->remove_property("effect_confused");
    }
    ::dest_effect();
}

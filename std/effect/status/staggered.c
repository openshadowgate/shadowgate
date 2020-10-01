#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_staggered");
}
int status_effect()
{
    int i;

    if (target->query_property("effect_staggered") > 1) {
        TO->remove();
        return;
    }

    target->set_property("effect_staggered", 1);

    tell_object(target, "%^RED%^You are staggered and can barely move.%^RESET%^");
    tell_room(ENV(target), "%^RED%^" + target->QCN + "'s face turns dull," + target->QS + " appears to be staggered.", target);


    call_out("dest_effect", ROUND_LENGTH * duration);
    return 1;
}

int dest_effect()
{
    int i;
    if (objectp(target)) {
        target->set_property("effect_staggered", -1);

        if (target->query_property("effect_staggered")) {
            tell_object(target, "%^RED%^You no longer feel staggered.%^RESET%^");
        }
        tell_room(ENV(target), "%^RED%^" + target->QCN + " no longer looks staggered.", target);
    }
    ::dest_effect();
    return 1;
}

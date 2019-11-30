#include <std.h>
#include <daemon.h>

inherit DAEMON;

int clevel;

int apply_to_weap(object weapon)
{


    return 1;
}

int disruptor_func(object obj)
{
    object targ, tp, etp;

    if(!objectp(obj))
        return 0;
    if(!objectp(environment(obj)) ||
       !living(environment(obj)))
        return 0;

    tp = environment(obj);
    etp = environment(tp);

    if(!objectp(etp))
        return 0;
    return 1;

}

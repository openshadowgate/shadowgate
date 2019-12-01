#include <std.h>
#include <daemon.h>

inherit DAEMON;

int disruptor_func(object obj)
{
    object targ, tp, etp;
    mapping winfo;
    int clevel, expiry;

    if(!objectp(obj))
        return 0;
    if(!objectp(environment(obj)) ||
       !living(environment(obj)))
        return 0;

    tp = environment(obj);
    etp = environment(tp);

    if(!objectp(etp))
        return 0;

    winfo = obj->query_property("temp_hit_bonus");

    clevel = winfo["clevel"];
    expiry = winfo["expiry"];

    if(expiry > time() || !expiry)
    {
        obj->remove_property_value("added short",({ "%^CYAN%^ (ablaze)%^RESET%^" }));
        obj->remove_property("temp_hit_bonus");
        return 0;
    }

    return 1;

}

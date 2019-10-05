#include <std.h>

int cmd_drain(string args)
{
    string targ,type;
    object targobj;
    if (!TP->is_vampire()&&
        !avatarp(TP))
    {
        return 0;
    }

    if (!args)
    {
        notify_fail("Target required.\n");
        return 0;
    }

    if(sscanf(args,"%s for %s",targ,type)!=2)
    {
        targ=args;
        type="life";
    }
    if(member_array(type,({"life","health"}))==-1)
    {
        notify_fail("Invalid drain type. Drain for life or health.\n");
        return 0;
    }
    if(!objectp(targobj=present(targ,ETP)))
    {
        notify_fail("No such target present.\n");
        return 0;
    }

    if(!(targobj->query_asleep()||
         targobj->query_unconscious()||
         targobj->query_paralyzed()))
    {
        notify_fail("Your target is not incapacitated.\n");
        return 0;
    }

    if(targobj->is_undead())
    {
        notify_fail("You should eat fresh food.\n");
        return 0;
    }
    write("all ok");
    return 1;
}

void help()
{
    write("");
}

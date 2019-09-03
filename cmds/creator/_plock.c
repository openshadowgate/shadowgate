#include <std.h>

#define SOFTLOCK "/daemon/softlock_d"

int cmd_plock(string args)
{
    if(!args ||
        args == "list")
    {
        mapping locks = SOFTLOCK->query_locks();
        mixed key;
        int now = time();
        write("%^BOLD%^Currently active pledges:");
        foreach(key in keys(locks))
        {
            write("%^BLUE%^"+key+" %^ORANGE%^"+locks[key][0]+"%^GREEN%^ "+locks[key][1]+" %^ORANGE%^"+parse_time(now - key - locks[key][2]));
        }
        return 1;
    }
}

void help()
{

}

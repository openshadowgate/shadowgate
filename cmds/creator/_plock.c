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
        write("%^WHITE%^%^BOLD%^Currently active pledges:");
        foreach(key in keys(locks))
        {
            write("%^BOLD%^%^BLUE%^"+key+" %^ORANGE%^"+sprintf("%8s",locks[key][0])+"%^GREEN%^ "+locks[key][1]+" %^ORANGE%^"+parse_time((key + locks[key][2]) - now));
        }
        return 1;
    }

    {
        int minutes;
        string desc;
        if(sscanf(args,"%d %s",minutes,desc)==2)
        {
            minutes=minutes>360?360:minutes;
            SOFTLOCK->add_lock(desc,minutes*60);
            return 1;
        }
    }

    {
        int key;
        if(sscanf(args,"remove %d",key)==1)
            SOFTLOCK->remove_lock(key);
        return 1;
    }

}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

plock - annoy other wizes

%^CYAN%^SYNTAX%^RESET%^

plock
plock %^ORANGE%^%^ULINE%^MINUTES%^RESET%^ %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^
plock remove %^ORANGE%^%^ULINE%^KEY%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this command you can place a pladge on certain files so others know you'll be working on it for N %^ORANGE%^%^ULINE%^MINUTES%^RESET%^.

Without an argument displays currently active pledges.

%^CYAN%^SEE ALSO%^RESET%^

stuff
");
}

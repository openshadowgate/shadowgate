#include <std.h>
#include <levelcheck.h>

int cmd_levelcheck(string str)
{
    object targ;
    if(!objectp(TP)) return 0;
    if (!str)
        return notify_fail("Levelcheck whom?\n");
    if(!(targ = find_player(TP->realNameVsProfile(str))))
        if(!(targ = present(str,ETP)))
            return notify_fail("That person is not available for levelcheck.\n");
    if(avatarp(targ))
        return notify_fail("That person is not available for levelcheck.\n");
    if(targ==TP)
    {
        write("%^BOLD%^%^WHITE%^You can use <kill "+TP->query_name()+"> to suicide freely.%^RESET%^");
        return 1;
    }
    switch(LEVELCHECK->levelcheck(TP,targ))
    {
    case 1:
        write("%^BOLD%^%^ORANGE%^You can engage in adventuring with them, but can't player kill them.%^RESET%^");
        break;
    case 2:
        write("%^BOLD%^%^BLUE%^You can engage in player kill with them, but can't adventure with them.%^RESET%^");
        break;
    case 3:
        write("%^BOLD%^%^GREEN%^You can engage in adventuring and player kill with them.%^RESET%^");
        break;
    default:
        write("%^BOLD%^%^RED%^You can't engage in adventuring and player kill with them.%^RESET%^");
        break;
    }
    return 1;

}

void help(){
    write(
"
%^CYAN%^NAME%^RESET%^

levelcheck - check if you're within level range

%^CYAN%^SYNTAX%^RESET%^

levelcheck %^ULINE%^%^ORANGE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will run a levelcheck on %^ULINE%^%^ORANGE%^TARGET%^RESET%^ and will output the result in human readable form. Three outcomes are possible and should be self-explanatory, allowing you to engage in both player kill and adventuring, adventuring only, or disallowing you both types of activities with %^ULINE%^%^ORANGE%^TARGET%^RESET%^. Please refer to %^ORANGE%^<help pkilling>%^RESET%^ and %^ORANGE%^<help rules>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

rules, pkilling, who, threaten, flag
");
}

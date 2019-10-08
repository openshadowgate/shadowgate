#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

int cmd_scoreproto(string args)
{
    string *output;
    object targ;

    if (args && avatarp(TP))
    {
        if(!(targ = find_player(args)))
        {
            return notify_fail("That person is not available for scoring.\n");
        }

        else if ((targ = find_player(str)))
        {
            if((int)targ->query_level() > (int)TP->query_level())
            {
                return notify_fail("That person is not available for scoring.\n");
            }
        }
    }
    else
    {
        targ = TP;
    }



}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

score - show your characters score sheet");
    if(avatarp(TP)) write("
%^CYAN%^SYNTAX%^RESET%^

score [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]");
    write(
        "
%^CYAN%^DESCRIPTION%^RESET%^

This command gives you overview of your character, listing many various facts about them.

%^CYAN%^SEE ALSO%^RESET%^

hp, stats, biography, money, inventory, eq
");
}

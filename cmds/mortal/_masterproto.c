#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <master_limits.h>

/**
 * @file
 */

mapping CLASSMAP=(["mage":MAGEKNOWN]);

int cmd_masterproto(string args)
{
    write("%^CYAN%^You are posing as a %^BOLD%^%^WHITE%^"+TP->query_class());
    if(!str)
    {

    }
}


void help()
{
    write("
%^CYAN%^NAME%^RESET%^



%^CYAN%^SYNTAX%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^


");
}

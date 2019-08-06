#include <std.h>

#define VALID_SETTINGS ({"simpleinv"})

int cmd_set(string args)
{
    string setting,value;
    function fs;
    if(sscanf(args,"%s %s",setting,value)!=2)
    {
        write("You must specify both setting and value.");
        return 1;
    }
    if(member_array(setting,VALID_SETTINGS)==-1)
    {
        write("Invalid setting.");
        return 1;
    }
    fs = (:TO,"set_"+$1,setting:);
    if(!functionp(fs))
    {
        write("Unable to find that setting.");
        return 1;
    }
    if(!(*fs)(value))
    {
        write("Unable to set "+setting+" to "+value+".");
        return 1;
    }
    else
    {
        write("Setting "+setting+" to "+value+".");
        return 1;
    }
    return 1;
}

int set_simpleinv(string val)
{
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

set - manipulate various mud settings

%^CYAN%^SYNTAX%^RESET%^

set %^ORANGE%^%^ULINE%^SETTING%^RESET%^ %^ORANGE%^%^ULINE%^VALUE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this command you manipulate numerous mud settings:

%^CYAN%^SEE ALSO%^RESET%^

score, threaten
");
}


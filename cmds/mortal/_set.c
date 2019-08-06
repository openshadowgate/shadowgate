#include <std.h>

#define VALID_SETTINGS ({"simpleinv","hints"})

int cmd_set(string args)
{
    string setting,value;
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
    if(!call_other(TO,"set_"+setting,value))
    {
        write("%^WHITE%^%^BOLD%^Unable to set %^RED%^"+setting+"%^WHITE%^ to %^RED%^"+value+"%^WHITE%^.");
        return 1;
    }
    else
    {
        write("%^WHITE%^%^BOLD%^Setting %^GREEN%^"+setting+"%^WHITE%^ to %^CYAN%^"+value+"%^WHITE%^.");
        return 1;
    }
    return 1;
}

int set_simpleinv(string val)
{
    string *valid_values = ({"on","off"});
    if(member_array(val,valid_values)==-1)
    {
        
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ "+implode(valid_values,", "));
        return 0;
    }
    if (val == "off")
        TP->delete("simple inventory");
    else
        TP->set("simple inventory", 1);
    return 1;
}

int set_hints(string val)
{
    string *valid_values = ({"on","off"});
    if(member_array(val,valid_values)==-1)
    {
        
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ "+implode(valid_values,", "));
        return 0;
    }
    if (val == "on")
        TP->delete("no hints");
    else
        TP->set("no hints", 1);
    return 1;
}

void help()
{
    //NOTE: PRESERVE FORMAT OF THIS HELPFILE FOR SORTING PURPOSES.
    //Use M-x sort-lines if you're using emacs or | sort in vim.
    write("
%^CYAN%^NAME%^RESET%^

set - manipulate various mud settings

%^CYAN%^SYNTAX%^RESET%^

set %^ORANGE%^%^ULINE%^SETTING%^RESET%^ %^ORANGE%^%^ULINE%^VALUE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

With this command you manipulate numerous mud settings:

%^GREEN%^hints %^MAGENTA%^on|off%^RESET%^\n  This will turn on or off displaying equipped inventory items in <inventory> command. When it is toggled off, you can see equipped inventory in <eq>. %^MAGENTA%^Default value is on.%^RESET%^
%^GREEN%^simpleinv %^MAGENTA%^on|off%^RESET%^\n  This will turn on or off displaying equipped inventory items in <inventory> command. When it is toggled off, you can see equipped inventory in <eq>. %^MAGENTA%^Default value is off.%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

score, threaten, prompt, speech, adjective, describe
");
}


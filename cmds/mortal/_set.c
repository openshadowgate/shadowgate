#include <std.h>
#include <daemons.h>

#define VALID_SETTINGS ({"hints","logon_notify","simpleinv","term","scrlines","scrwidth"})

int cmd_set(string args)
{
    string setting,value;
    if(args=="show")
    {
        string stng;
        write("%^BLUE%^--=%^BOLD%^<%^WHITE%^ Settings %^BLUE%^>%^RESET%^%^BLUE%^=--%^RESET%^");
        foreach(stng in VALID_SETTINGS)
        {
            write("%^BOLD%^%^WHITE%^"+capitalize(stng)+": %^RESET%^"+(string)call_other(TO,"get_"+stng));
        }
        return 1;
    }
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

string get_simpleinv()
{
    if(TP->query("simple inventory"))
        return "on";
    else
        return "off";
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

string get_hints()
{
    if(TP->query("no hints"))
        return "off";
    else
        return "on";
}

int set_term(string val)
{
    string *valid_values;
    valid_values = TERMINAL_D->query_terms();
    if(member_array(val,valid_values)==-1)
    {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ "+implode(valid_values,", "));
        return 0;
    }
    TP->setenv("TERM", val);
    TP->reset_terminal();
    return 1;
}

string get_term()
{
    return TP->getenv("TERM");
}

int set_scrlines(string val)
{
    if(!atoi(val))
    {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    if(atoi(val)<2)
    {
        write("%^BOLD%^%^RED%^Invalid value, must be bigger than 2.%^RESET%^");
        return 0;
    }
    TP->setenv("LINES", val);
    return 1;
}

string get_scrlines()
{
    return TP->getenv("LINES");
}

int set_scrwidth(string val)
{
    if(!atoi(val))
    {
        write("%^BOLD%^%^RED%^Invalid value, must provide a number.%^RESET%^");
        return 0;
    }
    if(atoi(val)<2)
    {
        write("%^BOLD%^%^RED%^Invalid value, must be bigger than 2.%^RESET%^");
        return 0;
    }
    TP->setenv("SCREEN", val);
    return 1;
}

string get_scrwidth()
{
    return TP->getenv("SCREEN");
}

int set_logon_notify(string val)
{
    string *valid_values = ({"on","off"});
    if(member_array(val,valid_values)==-1)
    {
        write("%^BOLD%^%^RED%^Invalid value, valid values are:%^RESET%^ "+implode(valid_values,", "));
        return 0;
    }
    if(val == "off")
        this_player()->set_logon_notify(0);
    else
        this_player()->set_logon_notify(0);            
    return 1;
}

string get_logon_notify()
{
    if(TP->query_logon_notify())
        return "on";
    else
        return "off";
}

void help()
{
    //NOTE: PRESERVE FORMAT OF THIS HELPFILE FOR SORTING PURPOSES.
    //Use M-x sort-lines if you're using emacs or |sort in vim.
    write("
%^CYAN%^NAME%^RESET%^

set - manipulate various mud settings

%^CYAN%^SYNTAX%^RESET%^

set %^ORANGE%^%^ULINE%^SETTING%^RESET%^ %^ORANGE%^%^ULINE%^VALUE%^RESET%^
set show

%^CYAN%^DESCRIPTION%^RESET%^

You can manipulate numerous mud settings:

%^CYAN%^hints %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of periodic hints. %^MAGENTA%^Default value is on.%^RESET%^\n
%^CYAN%^logon_notify %^GREEN%^on|off%^RESET%^\n  This will turn on or off display of people joining the game. %^MAGENTA%^Default value is on.%^RESET%^\n
%^CYAN%^simpleinv %^GREEN%^on|off%^RESET%^\n  This will turn on or off displaying equipped inventory items in %^ORANGE%^<inventory>%^RESET%^ command. When it is toggled off, you can see equipped inventory in %^ORANGE%^<eq>%^RESET%^. %^MAGENTA%^Default value is off.%^RESET%^\n
%^CYAN%^term %^GREEN%^"+implode(sort_array(TERMINAL_D->query_terms(),1),"|")+"%^RESET%^\n This will set your current terminal to a given value. The value 'unknown' sets terminal to the one without colors. %^MAGENTA%^Default value is set on first login.%^RESET%^\n
%^CYAN%^scrlines %^GREEN%^NUMBER%^RESET%^\n  Set how many lines appear for paged information. %^MAGENTA%^Default value: 20%^RESET%^\n
%^CYAN%^scrwidth %^GREEN%^NUMBER%^RESET%^\n  Set screen width for text wrapping. %^MAGENTA%^Default value: 75%^RESET%^\n
To see current values use %^ORANGE%^<set show>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

adjective, background, chfn, colors, describe, flag, lines, message, passwd, prompt, speech
");
}


//	_inventory.c written by Descartes October 1992

#include "move.h"
#include <std.h>
#include <daemons.h>

inherit DAEMON;

string alltext;

int worn_wielded(object ob)
{
    if(!objectp(ob)) return 0;
    if(undefinedp(ob->query_short())) return 0;
    if(ob->query_worn()) return 0;
    if(ob->query_wielded()) return 0;
    return 1;
}

int cmd_inventory() 
{
    object *items, *exclude = ({});
    int x,silly;
    string result;
    string short;
    string stuff;

    alltext = "";
    set_property("information",1);
    if(x=TP->light_blind(-1)) 
    {
        notify_fail(TP->light_blind_fail_message(x)+"\n");
        return 0;
    }
    if(TP->query_blind()) 
    {
        tell_object(TP,"You are blind, and can not see.");
        return 1;
    }
    items = all_inventory(this_player());
    result = "%^BOLD%^%^CYAN%^You are carrying:\n%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    if(USER_D->get_flag(TP, "simple inventory") == "On")
    {
        exclude = filter_array(items, "worn_wielded");
        items -= exclude;
        stuff = TP->describe_item_contents(items);
    }
    else stuff = TP->describe_item_contents(({}));
  
    if(stuff != "") 
    {
        stuff = "   %^BOLD%^%^GREEN%^"+stuff;
        stuff = replace_string(stuff,",","\n  %^GREEN%^%^BOLD%^");
        stuff = replace_string(stuff," are here.","");
        stuff = replace_string(stuff," is here.","");
    }
    if(stuff == "")
        result += "%^RED%^You are empty-handed.\n";
    else
        result = result + stuff;
    result += "%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    alltext += result;
    this_player()->more(explode(alltext,"\n"));
    return 1;
}

int help() {
   write("Command: inventory\nSyntax: inventory\n"+
         "This command gives you a list of the items\n"+
         "contained in your inventory.\n"
         "See also: score\n"
        );
   return 1;
}
/* EOF */

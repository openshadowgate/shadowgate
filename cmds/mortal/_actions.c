#include <std.h>

inherit DAEMON;

#define WEATHER ({"moon","sun","sky","sera","tyrannos","moons","stars"})

int cmd_actions(){
    string msg, *items, *searches, *actions;
    mapping *itemmap, *searchmap;
    int i,num;

// This section reports out the items you can look at in a room.
    msg = "You can <look> at the following items in this room: \n";
    itemmap = ETP->query_items();
    num = sizeof(itemmap);
    if (num > 0) {
       items = keys(itemmap);
       items -= WEATHER;
       // this if statement parses the array into a list separated by
       // commas and ending with a period. 
       for(i=0;i<sizeof(items)-1;i++)  { msg += items[i]+", "; }
       msg += items[i]+".\n";
    }
    tell_object(TP, msg+"\n"); 

// This section reports out the searches you can find in a room.
    msg = "You can <search> the following items in this room: \n";
    searchmap = ETP->query_searches();
    num = sizeof(searchmap);
    if (num > 0) {
       searches = keys(searchmap);
       // this if statement parses the array into a list separated by
       // commas and ending with a period. 
       for(i=0;i<num-1;i++)  { msg += searches[i]+", "; }
       msg += searches[i]+".\n";
    }
    tell_object(TP, msg+"\n"); 

// This section reports out the actions you can take in a room.
    msg = "You feel that you can take the following actions in this room: \n";
    actions = ETP->query_actions();
    num = sizeof(actions);
    if (num > 0 ) { 
       // this if statement parses the array into a list separated by
       // commas and ending with a period. 
       for(i=0;i<num-1;i++)  { msg += (string) actions[i]+", "; }
       msg += (string) actions[i]+"."; 
    }

    tell_object(TP, msg + 
     "\n\n%^BOLD%^%^CYAN%^Please note this will not tell you the object of a command. \n"
     +"%^BOLD%^%^CYAN%^Example: for %^GREEN%^<pull lever>%^CYAN%^ this command will "
     +"only show %^GREEN%^<pull>%^CYAN%^ and not %^GREEN%^<lever>%^CYAN%^.%^RESET%^\n"
     );
    return 1;
}

void help(){
    write("Syntax: <actions>\n\n"
      +"This command tells players about items that can be looked at <look item>, \n"
      +"items that can be searched <search item>, \n"
      +"and actions that can be taken in this room. \n\n"
      +"Please note this does not include items from astronomy such as: \n"
      +"%^BOLD%^%^RED%^sun, moon, moons, sky, stars, sera, and tyrranos.%^RESET%^" 
    );
}

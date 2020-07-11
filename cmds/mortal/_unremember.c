#include <std.h>
#define SYNOPSIS "Syntax:  unremember <location|object> <remembered label>\n"

inherit DAEMON;

int cmd_unremember(string str){
    string what, where;
    mapping remmap;
    string *remsort;

    if(!str)
        return notify_fail("Unremember what?\n");
    if(sscanf(str, "%s %s", what, where) != 2)
        return notify_fail(SYNOPSIS);
    if(what != "location" && what != "object")
        return notify_fail(SYNOPSIS);

    if(what == "location"){
       if(!remmap = TP->query_rem_rooms())
           remmap = ([ ]);
       if(!remsort = TP->query_rem_rooms_sort())
           remsort = ({ });

       if(member_array(where, remsort) == -1) {
           tell_object(TP, "You don't have that location memorized.");
           return 1;
       }

       remsort = distinct_array( (remsort - ({where})) );
       map_delete(remmap, where);
       TP->set_rem_rooms(remmap, remsort);
       tell_object(TP, "You concentrate and forget the location "+where+".");
    }

    if(what == "object"){
        if(!remmap = TP->query_rem_obs())
           remmap = ([ ]);
       if(!remsort = TP->query_rem_obs_sort())
           remsort = ({ });

       if(member_array(where, remsort) == -1) {
           tell_object(TP, "You don't have that object memorized.");
           return 1;
       }

       remsort = distinct_array( (remsort - ({where})) );
       map_delete(remmap, where);
       TP->set_rem_obs(remmap, remsort);
       tell_object(TP, "You concentrate and forget the object "+where+".");

    }

    return 1;
}

void help() {
     write(
"
%^CYAN%^NAME%^RESET%^

unremember - forget something

%^CYAN%^SYNOPSIS%^RESET%^

unremember location|object %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to forget locations and objects you have previvously remembered.

If you're looking to how to forget preared spell check %^ORANGE%^<help forget>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

remember, recall, forget, nickname
"
          );
}

//	/bin/user/_sites.c
//	from the Nightmare mudlib
//      for restricting access to characters from certain sites
//	created by Shadowwolf@Nightmare 
//      modified by Gregon@Nightmare to reflect changes in user.c
 
#include <std.h>
#include <security.h>
 
#define OK_CHARS ({ "1", "2","3","4","5","6","7","8","9","0",".","*" })
 
inherit DAEMON;
 
int cmd_sites(string str) {
    string *sites;
    string flag, num;
    int i, max;
 
    sites = (string *)this_player()->query_mysites();
    if(!str) {
        seteuid(UID_ROOT);
        seteuid(geteuid());
        if(!sizeof(sites))
          message("info", "You can login from anywhere.", this_player());
        else {
            message("info", "You may login from these sites:", this_player());
            this_player()->more(explode(format_page(sites, 5), "\n"));
        }
        return 1;
    }
    if(sscanf(str, "%s %s", flag, num) != 2) {
        notify_fail("Correct syntax: <sites>, <sites -a [site]>, or "
          "<sites -r [site]>\n");
        return 0;
    }
    for(i=0, max = strlen(num); i < max; i++) 
        if(member_array(num[i..i], OK_CHARS) == -1) {
            notify_fail("You should use the ip number, not the name.\n");
            return 0;
        }
    seteuid(UID_ROOT);
    if(flag == "-r"){
       sites-=({num});
       this_player()->set_mysites(sites);}
     else if(flag == "-a") {
       sites+=({num});
       this_player()->set_mysites(sites);}
    else {
        seteuid(getuid());
        notify_fail("Invalid flag: "+flag+"\n");
        return 0;
    }
    seteuid(getuid());
   if(flag == "-r") message("info", "Site "+str+" removed from sites "
      "list.", this_player());
    else message("info", "Site "+str+" added to sites list.",this_player());
    return 1;
}
 
void help() {
    message("help",
        "Syntax: <sites (-a|-r [ip number])>\n\n"
        "Sets a site that limits from where your character may login.  "
        "You may set more than one site and use a wild card.  You must "
        "nevertheless use the ip number and not the name.  For example, "
        "134.181.1.12   134.181.*   are both valid.\n\n", this_player()
    );
}

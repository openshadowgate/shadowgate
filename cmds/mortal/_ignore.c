#include <std.h>
#include <daemons.h>

inherit DAEMON;
int list_ignored(string *str);

int cmd_ignore(string str){
    string *ignored, rstr;
    string dink;

    ignored = TP->query_ignored();
    dink = FINGER_D->user_finger_display("jim");

    if(!str) return list_ignored(ignored);
    if(str == "clear"){
      TP->reset_ignored();
      tell_object(TP, "You are no longer ignoring anyone.");
      return 1;
    }
    str = lower_case(str);
    rstr = TP->realName(str);
    if(member_array(rstr, ignored) != -1){
      tell_object(TP, str+" is already on your ignored list.");
      return 1;
    }
    if((string)FINGER_D->user_finger_display(rstr) == dink){
      tell_object(TP, dink);
      return 1;
    }

    TP->add_ignored(rstr);
    tell_object(TP, "You are ignoring all tells from "+str+".");
    return 1;
}

int list_ignored(string *str){
    int i;

    tell_object(TP, "%^BOLD%^You are currently ignoring the following people:");
    for(i=0;i<sizeof(str);i++){
      tell_object(TP, TP->knownAs(str[i]));
    }
    return 1;
}

void help(){
    message("help",
      "Syntax: ignore :  Lists who you are currently ignoring.\n"
      "        ignore clear  : clears your ignore list and lets anyone send\n"
      "                      you a tell.\n"
      "        ignore <name> : Makes it so that <name> can't send you a tell,\n"
      "                        or reply to you.\n"
      "Allows you to ignore specific players.  For those of you that may want to ignore "
      "tells from a wiz, it wont work.\n\n"
      "See also: unignore, tellblock", this_player()
    );
}

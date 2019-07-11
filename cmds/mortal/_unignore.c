#include <std.h>

inherit DAEMON;
int list_ignored(string *str);

int cmd_unignore(string str){
    string *ignored, rstr;

    ignored = TP->query_ignored();
    if(!str) return list_ignored(ignored);
    if(str == "clear"){
      TP->reset_ignored();
      tell_object(TP, "You are no longer ignoring anyone.");
      return 1;
    }
    str = lower_case(str);
    rstr = TP->realName(str);
    if(member_array(rstr, ignored) == -1){
      tell_object(TP, "You are not ignoring "+str);
      return 1;
    }
    TP->remove_ignored(rstr);
    tell_object(TP, "You are no longer ignoring "+str);
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
      "Syntax: unignore\n"
      "        unignore clear\n"
      "        unignore <name>\n"
      "Opposite of ignore.  unignore alone shows you a list of the people you are ignoring.  unignore clear clears all the names from your ignored list.  unignore <name> removes the single name from your ignored list.\n\n"
      "See also: ignore, tellblock", this_player()
    );
}

//_tune.c
//A utility to help wizards keep track of what lines they're
//on, and to them turn all off and on with one command.
//rewritten to query current channels from user, by Belphy@shadowgate


#include <std.h>
inherit DAEMON;

int cmd_tune(string str) {

  string *ob, guild, blocked, unblocked;
  int i;

  ob = this_player()->query_channels();

  if(!str || str=="list") {
    blocked="";
    unblocked="";
    for(i=0; i<sizeof(ob); i++) 
      if(this_player()->query_blocked(ob[i]))
        blocked += " "+ob[i];
      else
        unblocked += " "+ob[i];
    message("info","Type 'help tune' for more options.",this_player());
    if (blocked != "")
      message("info","You are blocking:"+blocked+".",this_player());
    if (unblocked != "")
      message("info","You are not blocking:"+unblocked+".",this_player());
    return 1;
  }
  if(str=="in"){
    for(i=0; i<sizeof(ob);i++)
      if(this_player()->query_blocked(ob[i]))
        this_player()->set_blocked(ob[i]);
    return 1;
  }
  if(str=="out"){
    for(i=0; i<sizeof(ob);i++)
      if(!this_player()->query_blocked(ob[i]))
        this_player()->set_blocked(ob[i]);
  return 1;
  }
  for(i=0; i<sizeof(ob);i++) {
    if(str==ob[i]) {
      this_player()->set_blocked(ob[i]);
      return 1;
    }
  }
  message ("info", "Please use 'help tune' for usage instructions.",this_player());
  return 1;
}

void help(){
  message("help","Syntax: tune [ list | in | out | <channel name> ]\n\n"
      "With no argument this command will display the status "
      "of the lines to which you have access.  With the argument in|out "
      "it will tune all of the lines either in or out.  The [list] argument "
      "is the same as just typing 'tune'.  <channel name> argument will toggle "
      "that channel tuned in/out.  Identical to just typing the <channel name> "
      "with out the 'tune' command; yet, included for player ease.\n\n"
      "Type: list <channel name>   to get a list of current listeners on a channel.\n\n"
      "See also: communication ",this_player());
}

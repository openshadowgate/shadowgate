//      /bin/user/_where.c
//      from the Nightmare mudlib
//      created 30 March 1993 by Billbo Baggins esq.
//      redone to use mapping, by Valodin, July 1, 1993

#include <databases.h>
#include <std.h>

inherit DAEMON;

private mapping sites;

int privileged;

void load_info();
string query_info(object ob);

void create() {
    seteuid(getuid());
    load_info();
    privileged = 0;
}

void load_info() {  
  int i, tmp;
  string *str;
  string *line;

  sites = ([]);
  str = ({ 0, 0, 0, 0, 0 });
    for(i=0, tmp = sizeof(line = read_database(WHERE_DB)); i<tmp; i++) {
    if(sscanf(line[i],"%s.%s.%s.%s:%s",str[0],str[1],str[2],str[3],str[4])!=5)
      continue; 
    if(!sites[str[0]])
      sites[str[0]] = ([]);
    if(!sites[str[0]][str[1]])
      sites[str[0]][str[1]] = ([]);
    if(!sites[str[0]][str[1]][str[2]])
      sites[str[0]][str[1]][str[2]] = ([]);
    sites[str[0]][str[1]][str[2]][str[3]] = str[4];
  }
}

string query_info(object ob) {
    string host,*str,*info;
    string pre, post;
    int i;

    pre = ""; post = "";
    
  privileged = archp(TP);
       if(ob->query_property("where block"))
      if(privileged)
	{
	  pre = "[";
	  post = "]";
	}
  else {
        privileged=0;
        return "Anonymous"; }
    host=query_ip_number(ob);
    info=explode(host,".");
    // limited to at least 2 digits precision
    if(!sites[info[0]] || !sites[info[0]][info[1]]) return pre + "Unknown" +
      post;
    if(!sites[info[0]][info[1]][info[2]])
    {
      if(!sites[info[0]][info[1]]["*"]) return pre + "Unknown" + post;
      if(!sites[info[0]][info[1]]["*"]["*"]) return pre + "Unknown" + post;
      return pre + (string)sites[info[0]][info[1]]["*"]["*"] +  post;
    }
    else if(!sites[info[0]][info[1]][info[2]][info[3]])
    {
      if(!sites[info[0]][info[1]][info[2]]["*"]) return pre + "Unknown" + post;
      return pre + (string)sites[info[0]][info[1]][info[2]]["*"] + post;
    }
    else
      return pre + (string)sites[info[0]][info[1]][info[2]][info[3]] + post;
    return pre + "Unknown" + post;
}

int cmd_where(string str1) {
    int i, tmp;
    string str;
    object *list;

    if(str1 == "block") {
        if(this_player()->query_property("where block")) 
	  write("Location blocking off.");
        else write("Now blocking location information.");
        this_player()->set_property("where block",
	      (this_player()->query_property("where block") ? -1 : 1)
        );
        return 1;
    }
    
    if(!avatarp(TP)) return 0;
    
    list=users();
    load_info();

    if((str = (string)this_player()->query_position()) == "arch" || 
       str == "head arch" || str == "administrator")
      privileged = 1;
    else
      privileged = 0;

    str = "";
    for(i=0, tmp = sizeof(list); i<tmp; i++) {
        if(list[i]->query_invis() && (int)TP->query_highest_level() < (int)list[i]->query_highest_level())
	  continue;
  if ( wizardp(list[i]) && !wizardp(TP) && list[i]->query_quietness() )
     continue;
   if(list[i]->query_true_name()) {
      if(avatarp(list[i]))
         str += arrange_string(capitalize((string)list[i]->query_vis_name()),17);
      else
         str += arrange_string(capitalize((string)list[i]->query_true_name()),17);
        str += query_info(list[i]);
        str += "\n";
   }
    }
    this_player()->more(explode(str, "\n"));
    sites = ([]);
    privileged = 0;
    return 1;
}

void help() {
    write("Syntax: <where>\n\n"
        "Lists all players online and the towns from which those players\n"
       "whose machine site locations are known.  If your site is marked\n"
        "<mail superuser> with the town your *machine* is located in and\n"
        "the ip # (four numbers separated by a period).\n"
        "\nOptional: <where [block]>\n\n"
        "Allows you to keep your location anonymous.\n"
        "See also: users, who\n"
    );
}

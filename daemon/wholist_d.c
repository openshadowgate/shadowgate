#include <std.h>
#include <html_converter.h>
#define OUTPUT "/d/save/wholist.php"
inherit DAEMON;

int clean_up(){return 1;}

void write_who(){
  int i,j,lines,lines2;
  string names = ({});
  string wizes = ({});
  string avatars = ({});
  string nonplayers = ({});
  string temp,out;
  object ob;
  object * who = users();
  object * retired = ({ });
  j = sizeof(who);
  for(i = 0;i<j;i++){
    if(wizardp(who[i]))
      wizes += ({who[i]->query_name()});
    else
      names += ({who[i]->query_name()});
  }
  names = sort_array(names,"sort_by_name",TO);
  wizes = sort_array(wizes,"sort_by_level",TO);
  retired = "/daemon/filters_d"->query_retired();
  nonplayers = retired->query_name();
//  nonplayers = sort_array(nonplayers,"sort_by_name",TO);
  out="<!DOCTYPE html>
<html>
<head>
<link href=\"wholist.css\" rel=\"stylesheet\" type=\"text/css\">
</head>
<body>";

  j = sizeof(wizes);
  for(i=0;i<j;i++){
    if(!objectp(find_player(wizes[i]))) continue;
    if(find_player(wizes[i])->query_true_invis()) continue;
    out += "Staff: "+CONVERTER->convertFromInput(find_player(wizes[i])->query_title())+"<br /><font color=\"#FFFFFF\">\n";
  }
  if(sizeof(wizes)) out +=  "<br />";

  j = sizeof(retired);
  for(i=0;i<j;i++){
    if(!objectp(ob=retired[i])) continue;
    out += CONVERTER->convertFromInput(ob->query_title())+"<br /><font color=\"#FFFFFF\">\n";
  }

  j = sizeof(names);											
  for(i=0;i<j;i++){
    if(!objectp(find_player(names[i]))) continue;
    out += CONVERTER->convertFromInput(find_player(names[i])->getWholeDescriptivePhrase())+"<br /><font color=\"#FFFFFF\">\n";
  }
  out += "<br /><br />";
  lines = sizeof(retired) + sizeof(names) + sizeof(wizes);
  if(sizeof(wizes)) lines++;
  lines2 = 16 - lines;
  if(lines2 < 0) lines2 = 0;
  if(lines2) {
    for(i=0;i<lines2;i++) out += "<br />";
  }
  out+="</body></html>\n";
  write_file(OUTPUT+"1",out);
  cp(OUTPUT+"1",OUTPUT);
  rm(OUTPUT+"1");
  
  call_out("write_who",60);
}

int sort_by_name(string name1, string name2) {
  //write("names = "+name1+" "+name2);
  if(!stringp(name1)) return 1;
  if(!stringp(name2)) return -1;
  return strcmp(name1,name2);
}

int sort_by_level(string name1, string name2){
  object ob,ob2;
  if(!stringp(name1)) return -1;
  if(!stringp(name2)) return 1;
  ob = find_player(name1);
  ob2 = find_player(name2);
  if(!objectp(ob) || !objectp(ob2)) return strcmp(name1,name2);
  if(ob->query_highest_level() > ob2->query_highest_level()) return 1;
  if(ob->query_highest_level() < ob2->query_highest_level()) return -1;
  return strcmp(name1,name2);
}

void create(){
  seteuid(getuid());
  write_who();
}


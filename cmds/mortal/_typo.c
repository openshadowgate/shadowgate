//Adapted from hmboard command and using coding from current bug report
//for logging, temp file, etc. to use direct_post.  To save spamming mail 
//of inactive immortals and streamline related communication *Styx*  6/2002
//changed to allow a string title for reports on commands or objects not present, etc. *Styx* 2/8/03


#include <std.h>
#include <dirs.h>
#include <security.h>

inherit DAEMON;

void do_post(string str);
string file, title;

int cmd_typo(string str) {
  if(!str)
     return notify_fail("Please specify a target or 2-3 word title.\n");
  if(strlen(str) > 30)
     return notify_fail("Please be more brief on the title, less than 30 characters.\n  You can elaborate in the editor.\n");
  do_post(str);
  return 1;
}

void do_post(string str) {
//   string file;
   string trash;
   object ob;
   write("You are about to post to a board for the immortals saying there is a "
         "typo related to %^BOLD%^%^YELLOW%^"+str+"%^RESET%^.  If you "
         "specified 'here', it will report the specific room you are "
         "in.  %^BOLD%^Please type in your message below.  "
         "%^RESET%^Feel free to copy/paste the relevant text from your screen "
         "and please indicate the corrections needed.\n");
   if(ob = present(str,TP) || ob = present(str, ETP) ) {
      file = base_name(ob);
      title = file;
   }
   if(str == "here") {
      file = base_name(ETP);
      title = file;
   }
   if(!file) {
      title = str;
      file = base_name(ETP); 
   }
   if(!file) 
      file = base_name(ETP); 

    rm(DIR_TMP+"/"+geteuid(previous_object())+".typo");
    previous_object()->edit(DIR_TMP+"/"+geteuid(previous_object())+".typo",
          "end_edit", TO);
    return;
}

end_edit() {
  string *lines;
  string tmpfile;
    tmpfile = file+":\n"+read_file(DIR_TMP+"/"+geteuid(TP)+".typo");
    lines = explode(wrap(replace_string(tmpfile, "\n", " "), 72), "\n");
  rm("/tmp/"+TPQN+".typo");
  report(lines);
}
 
report(string *lines) {
  string who, trash, *elements;
  int x;
  string message;

  elements = explode(file, "/");
  if(elements[0] == "realms") who = elements[1];
  else if(elements[0] == "d") who = elements[1];
  else who = 0;
  seteuid(UID_LOG);
  log_file("typos", "Typo reported by "+capitalize(TPQN)+" "+ctime(time())+":\n");
  if(who) log_file("reports/"+who, "Typo reported by "+
                    capitalize(TPQN)+":\n");
               
  x = -1;
  while(++x < sizeof(lines)) {
    log_file("typos", lines[x]+"\n");
    if(who) log_file("reports/"+who, lines[x]+"\n");
  }
  message = lines[0]+"\n";
  x=0;
  while(++x < sizeof(lines)) {
     message += lines[x]+"\n";
  }
  message = message + "\nReported by:  "+identify(TP)+" from location "
     +base_name(ETP)+" on "+ctime(time())+" related to %^BOLD%^"
     +file+"%^RESET%^.\n\n";
//  title = file;
  if (strlen(title) > 30) {
     while(strlen(title) > 29)
        sscanf(title, "%s/%s", trash, title);
        title = "~" + title;
  }
  seteuid(UID_CRESAVE);
  "/adm/daemon/bboard_d.c"->direct_post("typoboard",capitalize(TPQN),title,message);
  seteuid(getuid());
  file = 0;
  write("Typo reported!  Thank you!\n");
  return 1;
}
 
void abort() {
  notify_fail("Typo report aborted.\n");
  rm("/tmp/"+TPQN+".typo");
  file = 0;
  return 0;
}

int help(){
  write(
@STYX
     typo [here | targetid | brief description]
  
  Puts you into a board message editor to send wizzes info. about a typo
  you've encountered.  Please specify a valid target if possible.
  
  %^BOLD%^typo targetid %^RESET%^- use a valid id for the object or mob in your inventory
  or the room you're in (i.e. you can "look monstername", so if the typo
  is with the monster, type "typo monstername").  

  %^BOLD%^typo here%^RESET%^ - will send us the room name you are in, use if the typo is with the room

  If the typo is not directly related to the room you are in or a mob or item present, please give a 2-3 word descriptive title such as %^BOLD%^<typo spellname, command name, etc.> or <typo town crier> %^RESET%^ (if target is already deceased or not in the room) etc.

  
  This command is to allow you to report typos to wizzes so we can
  continue our quest to eradicate them.    

see also:  bug, praise
STYX
  );
  return 1;
}

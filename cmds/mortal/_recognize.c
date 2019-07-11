//_recognize.c

#include <std.h>

inherit DAEMON;

int help();

int cmd_recognize(string str){
    string who,as;
    object ob, *usrs;
    int x;

   if (TP->query_blind()) return notify_fail("You can't see a thing!\n");
    if(!str) {
        return help();
    }
    if(str == "all"){
       if(!avatarp(TP) && !TP->query("test_character")){
          tell_object(TP,"Sorry, only immortals can use this command.");
          return 1;
       }
       usrs = users();
       for(x = 0;x < sizeof(usrs);x++) {
           TP->addRelationship(usrs[x],usrs[x]->query_name());
       }
       write("All players online have been recognized.");
       return 1;
    }
    if(sscanf(str, "%s as %s",who, as) != 2) {
        return help();
    }
    ob = present(who,ETP);
    if(!objectp(ob) || wizardp(ob)) {
      return notify_fail("There is no "+who+" here.\n");
    }
    else{
        if(userp(ob)){
            write("You will recognize "+who+" as "+capitalize(as)+".");
            TP->addRelationship(ob,as);
        }
        else{
            write("You can only recognize other players at this time.");
        }
    }
    return 1;
}

int help(){
    write(
@HELP
Usage:

recognize <who> as <some name>

Allows you to recognize another player by a description, if you do not
know the person by name.

HELP
    );
    if(avatarp(TP)){
       write("As an immortal, you can <recognize all> to "
          "recognize all players online as their real names.");
    }
    return 1;
}


//      /bin/user/_quests.c
//      gives a player's quests

#include <daemons.h>
#include <clock.h>

#include <std.h>

inherit DAEMON;

int check_permission(object ob,object player)
{
    string pos,name;
    if(!objectp(player)) { return 1; }
    name = (string)ob->query_true_name();
    pos = lower_case((string)player->query_position());
    if(pos == "builder" || pos == "apprentice")
    {
        if(lower_case(name) != lower_case((string)player->query_true_name()))
        {
            tell_object(player,"You can only use this on yourself.");
            return 0;
        }
    }
    return 1;
}

int cmd_quests(string str) {
    int *pk;
    int birth, birth2, byear, i, max;
    object targ;
    string *kills, *quests;
    mixed *deaths, *oh, *divorced;
    string borg, tmp, check;
    mapping minis;
    string *lines,*test;
    if(str && avatarp(TP)) {
        if(!(targ = find_player(str)) || targ->query_highest_level() > TP->query_highest_level()) {
            write("That person is not online.\n");
            return 1;
        }
    }
    else {
        targ = TP;
    }
    if(!check_permission(targ,TP)) { return 1; }
    if(targ == TP) {
        tmp = "You have";
    }
    else {
        tmp = capitalize(targ->query_name()) + " has";
    }
    borg = "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    borg += "%^YELLOW%^" + (string)targ->query_short()+"\n\n";
/*    
    birth = (int)TP->query_birthday();
    birth2 = birth - (int)TP->query_start_age() * YEAR;
    byear = year(birth2);
    borg += "\n%^CYAN%^You were born %^MAGENTA%^"+day(birth)+", %^GREEN%^"+date(birth)+" %^MAGENTA%^"+month(birth)+
      " %^GREEN%^"+(byear ? (byear<0 ? (-byear)+" %^MAGENTA%^SG.\n" : byear+" %^MAGENTA%^SG.\n") : " of the null year.\n");
    if(!(oh = (mixed *)targ->query_current_marriage()))
      borg += "%^CYAN%^You are currently single.\n";
    else if(!oh[1])
      borg += "%^CYAN%^You married %^GREEN%^"+capitalize(oh[0])+"%^CYAN%^ on a forgotten date.\n";
    else
      borg += "%^CYAN%^You married %^GREEN%^"+capitalize(oh[0])+"%^CYAN%^ on "+month(oh[1])+" "+
        date(oh[1])+", "+year(oh[1])+".\n";
    borg += "\n";
*/    
    if(!sizeof(minis = (mapping)targ->query_mini_quest_map()))
      borg += "%^CYAN%^" + tmp+" no meaningful accomplishments.\n";
    else {
      borg += "%^CYAN%^" + tmp + " been rewarded for the following great deeds:\n";
      i = sizeof(quests = keys(minis));
      while(i--) {
        borg += "%^RED%^"+date(minis[quests[i]][0])+" "+month(minis[quests[i]][0])+
          " "+year(minis[quests[i]][0])+" SG: %^RESET%^"+minis[quests[i]][1]+"\n";
        }
        borg += "\n";
    }

    if(!sizeof(test = targ->query_quests()))
      borg += "%^CYAN%^" + tmp + " not completed any quests.\n";
    else {
      borg += "%^CYAN%^" + tmp+ " completed the following quests:\n";
      i = sizeof(test);
      while(i--) {
             borg += sprintf("%-16s\n",test[i]);
        }
        borg += "\n%^YELLOW%^";
    }

    borg += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    TP->more(explode(borg, "\n"));
    return 1;
}


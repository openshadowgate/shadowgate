//

#include <std.h>
#include <security.h>
#include <daemons.h>

void create() { seteuid(getuid()); }

int help(){

    write(
@OLI
    %^YELLOW%^READ CAREFULLY%^RESET%^


   usage permadeath <player name> (works on off line players as well>
         permadeath <player name> <time> <unit>
         permadeath pardon <player name>

   permadeath pardon <player name> will remove the permadeath flag 
   of the player you specify and will allow them to log back in. 
   
   This can really screw someone up if misused. Note that time of larger
   then 2 months is essentially real permadeath as purge will get them.

   Always start with minutes. the units are:
       min
       hour
       days

       If you want more than that get a calculator.

  This will flag a player so the next pk will result in the player being
  kicked from the mud and locked out for that period of time. The flag
  will remain until undone. Please remove the flag when done. You remove
  the flag by entering 0 as your time.
OLI
      );
    write(
@OLI
    Examples of why to set flag.
    disrespecting death
    using death to escape RP
    Not role playing death
    In some cases when a very powerful player is beaten by a lesser player
OLI
    );
    return 1;

}


int cmd_permadeath(string str){
    string who, unit, tmp;
    int length, orig_length;
    object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) {
        return help();
    }

    if(sscanf(str,"%s %s",tmp,who) == 2) {
        if(tmp == "pardon") {
            if(PERMA_DEATH_D->is_perma_deathed(who)) {
                PERMA_DEATH_D->remove_player(who);
                log_file("permadeath_flag","On "+ctime(time())+": "+
                capitalize(TP->query_name())+" pardoned "+who+"\n");
                write("You have pardoned "+who+" of their "+
                "permadeath.");
                return 1;
            }
            write("No such user has been marked for permadeath.");
            return 1;
        }
//        return help();
    }

    if (sscanf(str, "%s %d %s",who, length, unit) != 3){
        who = str;
        length = "/adm/daemon/user_call"->user_call(who,"get_perma_death_flag");
        if (length%3600){
            write(capitalize(who)+" is flagged for a "+length/60+" minute perma death.");
        } else if(length%86400) {
            write(capitalize(who)+" is flagged for a "+length/3600+" hour perma death.");
        } else {
            write(capitalize(who)+" is flagged for a "+length/86400+" day perma death.");
        }
       length = "/adm/daemon/user_call"->user_call(who,"get_perma_death");
       if (length > time()) {
          write(capitalize(who)+" is DECEASED until: "+ctime(length)+".\n");
       }
        return 1;
    }

  who=lower_case(who);
  orig_length=length;
  ob=find_player(who);
    if(!objectp(ob)) {
        return notify_fail("Player not found");
    }
    if(avatarp(ob)) {
        return 0;
    }

    if(unit == "min") {
        length = length*60;
    } else if(unit ==  "hour"){
        length = length*3600;
    }else if(unit == "days") {
        length = length*86400;
    } else {
        write("Unknown unit for time.");
        return 1;
    }
    ob->set_perma_death_flag(length);
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" %^B_BLUE%^%^WHITE%^was marked for perma death for "+orig_length+" "+unit+"%^RESET%^%^B_BLACK%^.");
   seteuid(UID_LOG);
   log_file("permadeath_flag","On "+ctime(time())+":"+capitalize(who)+" was marked for perma death for "+orig_length+" "+unit+".\n");
  seteuid(getuid());

    write(capitalize(who)+" will be locked out for "+length+" seconds upon all future pks suffered.");
    return 1;

}

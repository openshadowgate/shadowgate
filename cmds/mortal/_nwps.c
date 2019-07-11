//adapted by *Styx* to allow avatar/wizzes to check player nwps
//added a few clarifications to the help *Styx* 9/6/02

#include <std.h>
#include "/daemon/nwps_d.h"
#define NWP_D "/daemon/nwps_d"

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

int cmd_nwps(string str){
    string *profs;
    int i,j, levels, days;
    string dis, exp;
    object ob;
    tell_object(TP,"%^BOLD%^%^MAGENTA%^Please see the %^WHITE%^skills%^MAGENTA%^ command.%^RESET%^");
/*    if(avatarp(TP)) {
      if(!str || str=="me")   
         str=(string)TP->query_name();
      if(!ob=find_player(str)){
         notify_fail(capitalize(str)+" is not in our reality.\n");
         return 0;
      }
      if(!check_permission(ob,TP)) { return 1; }
      if(ob->query_invis() && ob->query_lowest_level() > TP->query_lowest_level()){
         notify_fail(capitalize(str)+" is not in our reality.\n");
         return 0;
      }
      tell_object(TP,"%^BOLD%^%^MAGENTA%^The nwps for %^WHITE%^"
        +capitalize(str)+" %^MAGENTA%^are as follows.");
    }
// only immortals can review nwps other than their own
   if(!avatarp(TP))  ob = TP;
       
        profs = ob->query_nwps();
        dis = arrange_string("Proficiency",20);
        dis += arrange_string("Level",15);
        dis+= arrange_string("exp cost for next",19);
        dis+= arrange_string("last trainer",17);
        
        write(dis);
        write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        for (i = 0;i<sizeof(profs);i++) {
            dis= arrange_string(profs[i],20);

            dis += arrange_string(""+ob->query_nwp(profs[i]),15);
            //exp = sprinf("%d",NWP_D->calc_exp_for_next(profs[i],ob));
            //dis += NWP_D->calc_exp_for_next(profs[i],ob);
            j = NWP_D->calc_exp_for_next(profs[i],ob);
            dis = dis + j;
            dis = arrange_string(dis, 54);
            write(dis+(string)ob->query(profs[i]+" master"));
        }
     levels = "/adm/daemon/calc_stuff_d.c"->num_nwp_levels(ob);
     days = "/adm/daemon/calc_stuff_d.c"->calc_age_days(ob);
     if(avatarp(TP)) {
        write("Immortal eyes only atm since it would give away online days....");
	write("   Total NWP levels excluding 'free' class ones:  "+levels);
	if(days) { 
	   write("     %^BOLD%^ NWP levels (non-free) per online day:  "
	     "%^B_MAGENTA%^"+levels/days+"."+((levels*10/days)-(levels/days))+"%^RESET%^");
	   return 1;
 	}
	else write("     no levels/day calc, < 1 day online time");
     }*/
     return 1;
}

/*int help(){
    int i;
    if(avatarp(TP)) 
    write("Immortals can check the nwps of a player with %^BOLD%^<nwps [name]>.\n"
"%^RESET%^Just nwps will return your nwps.\n");
    write(
@HELP
   <nwps> shows current nwps, the level and the exp cost to the next level
   
Non-weapon proficiencies (nwps) are non-adventuring-related abilities.  
They offer abilities that will expand a character - from the ability to 
write fluently to being able to repair armor. They will be constantly 
expanding.  The level of proficiency has no relation to your class level 
unless the prof is tied directly to your class (for example, riding and 
knights).  The experience to next nwp level is tied to the amount of 
practicing that you need to do to advance again. 

You can advance in an nwp by being apprenticed by a player or NPC.  If 
they are capable and willing, and you have not learned previously from 
a higher level teacher, they will ask if you wish to accept their training.
HELP
    );
    write(
@HELP2
%^BOLD%^Note:  %^RESET%^To request training from an NPC - say "apprentice 
me in [nwpname]".  You can add please, etc. but those words must all be 
together in the say.  To accept their offer, %^BOLD%^<apprentice accept> 
%^RESET%^(typed as a command, not a say).

Help for the nwps is generally under the command name, which will be 
without the "ing" - i.e. help heal, help heal mount, help tailor.

see also:  apprentice, nwp_skills, 
	   crafted (to manage items you create with the various nwps)

Here is a list of currently defined nwps (these may not all be in the 
game as a wiz needs to define them before any work can be done.)
HELP2
     );
    for (i = 0;i<sizeof(keys(NWPS_MAP));i++) {
        write("\t"+keys(NWPS_MAP)[i]);
    }
    return 1;
}
*/

int help(){
    write(
@HELP
    See: "help skills"
HELP
    );
    return 1;
}
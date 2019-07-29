//     _hp.c
//     Command <hp> is quick and alot easier than status.
//     Created by Firedragon on 12/21/96 
//Updated by ~Circe~ 4/29/11 so avatars and above could use it on other targets
// Updated by ~Circe~ 9/25/15 to include power points for psionic characters
 
#include <std.h>

#define RED     "%^RED%^"
#define GREEN   "%^GREEN%^"
#define YELLOW  "%^YELLOW%^"
#define BOLD    "%^BOLD%^"

inherit DAEMON;

string posxxx;


 
int cmd_hp(string str) {
  int temp1, temp2, max;
  string hunger, thirst, sober, poison;
  object targ;
    if (str && avatarp(TP)) {
        if(!objectp(TP)) { return 0; }
        posxxx = lower_case((string)TP->query_position());
        if(posxxx == "builder" || posxxx == "apprentice")
        {
            tell_object(TP,"You cannot use this command as a builder or apprentice.");
            return 1;
        }
        if(!(targ = find_player(str))) 
        {
            return notify_fail("That person is not available for scoring.\n");
        }
        
        else if ((targ = find_player(str))) {
            if((int)targ->query_level() > (int)TP->query_level())
            {
                return notify_fail("That person is not available for scoring.\n");
            }        
        }
   } else {
      targ = TP;
   }

   max = targ->query_formula();
   temp1 = targ->query_stuffed();
   temp2 = max / 6;
   if(temp1 < temp2) hunger = BOLD+RED+"Starving";
   else if(temp1 < (temp2 * 2)) hunger = RED+"Very hungry";
   else if(temp1 < (temp2 * 3)) hunger = RED+"Really hungry";
   else if(temp1 < (temp2 * 4)) hunger = YELLOW+"Hungry";
   else if(temp1 < (temp2 * 5)) hunger = GREEN+"Not hungry";
   else hunger = BOLD+GREEN+"Stuffed";
   temp1 = targ->query_quenched();
   temp2 = max / 6;
   if(temp1 < temp2) thirst = BOLD+RED+"Parched             ";
   else if(temp1 < (temp2 * 2)) thirst = RED+"Very thirsty        ";
   else if(temp1 < (temp2 * 3)) thirst = RED+"Really thirsty      ";
   else if(temp1 < (temp2 * 4)) thirst = YELLOW+"Thirsty             ";
   else if(temp1 < (temp2 * 5)) thirst = GREEN+"Not thirsty         ";
   else thirst = BOLD+GREEN+"Quenched            ";
   temp1 = targ->query_intox();
   temp2 = max / 5;
   if(temp1 == 0) sober = GREEN+"Sober          ";
   else if(temp1 < temp2) sober = YELLOW+"Buzzed         ";
   else if(temp1 < (temp2 * 2)) sober = YELLOW+"Tipsy          ";
   else if(temp1 < (temp2 * 3)) sober = RED+"Lipped         ";
   else if(temp1 < (temp2 * 4)) sober = RED+"Drunk          ";
   else sober = BOLD+RED+"Wasted         ";
   poison = "";
   if((int)targ->query_poisoning() > 0) {
        poison = "\n%^RESET%^Poison:  %^RED%^Poisoned";
   }
 
   if(targ != TP){
      write("%^BOLD%^%^WHITE%^Basic information for %^CYAN%^"+targ->QCN+" %^WHITE%^is as follows:%^RESET%^");
   }
  write("%^WHITE%^HP: %^BOLD%^%^GREEN%^"+ targ->query_hp()
	+"%^WHITE%^/%^RESET%^%^GREEN%^"+ targ->query_max_hp() 
	+"  %^WHITE%^EXP: %^BOLD%^%^GREEN%^"+ targ->query_exp()
	//+"  %^RESET%^AC: %^BOLD%^%^GREEN%^"+ targ->query_ac()
	+"  %^RESET%^Carrying: %^BOLD%^%^GREEN%^"+targ->query_internal_encumbrance()
	+"%^WHITE%^/%^RESET%^%^GREEN%^"+ targ->query_max_internal_encumbrance()
      +"%^RESET%^\nStamina: %^CYAN%^"+targ->query_condition_string()
	+"%^RESET%^\nIntox:  "+sober
	+"%^RESET%^\nHunger:  "+hunger+"  %^RESET%^Thirst:  "+thirst+"%^RESET%^"+
    poison
	);
  if(targ->is_class("psion") || targ->is_class("psywarrior")){
      write("%^RESET%^Power Points: %^BOLD%^%^GREEN%^"+targ->query_mp()+"%^RESET%^/%^GREEN%^"+targ->query_max_mp()+"");
  }
  if(targ->is_class("monk") && (int)targ->query_class_level("monk") > 1)
  {
      write("%^RESET%^Ki: %^BOLD%^%^CYAN%^"+targ->query("available ki")+"%^RESET%^/%^CYAN%^"+targ->query("maximum ki")+"");
  }
  return 1;
}


void help() {
    write("
%^CYAN%^NAME%^RESET%^

hp - display hitpoints, stamina, carrying capacity

%^CYAN%^DESCRIPTION%^RESET%^

This command displays briefly your status.

%^CYAN%^SEE ALSO%^RESET%^

score, report, stats, skills, languages, inventory
");
  
}

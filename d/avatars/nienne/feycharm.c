#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int awaters, awinds, aearth, aflames;

void create() {
   ::create();
   set_name("oaken ring");
   set_id(({"ring","oaken ring","oak ring","carved ring","carved oaken ring",""}));
   set_short("%^RESET%^%^ORANGE%^B%^CYAN%^a%^ORANGE%^nd o%^BOLD%^%^BLACK%^f %^RESET%^%^ORANGE%^El%^RESET%^e%^ORANGE%^men%^RED%^t%^ORANGE%^s%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^carved oa%^RED%^ke%^ORANGE%^n ring%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This band is wide, but narrow and surprisingly %^GREEN%^lightweight%^ORANGE%^. Its surface is "
"%^MAGENTA%^glossy-smooth%^ORANGE%^, marked with the growth whorls of the oaken wood from it must surely have been shaped. "
"At four equidistant points around the outer surface symbols have been etched into the smooth wooden surface and brightened "
"with some kind of pigment. %^RESET%^Three horizontal rippled lines in white%^ORANGE%^, %^CYAN%^an ovoid sphere of blue"
"%^ORANGE%^, %^BOLD%^%^BLACK%^two sharp peaks of dull brown%^RESET%^%^ORANGE%^, and %^RED%^two vertical rippled lines in "
"crimson%^ORANGE%^.%^RESET%^\n");
   set_lore("%^BOLD%^%^WHITE%^Such an item is a prized gift from the fey, representing the balance of the four elements "
"and their gifts to the world. As fine a gift as this would only be granted to those who have truly aided such creatures "
"in a time of need, as recognition of their efforts.");
   set_limbs(({"left hand","right hand"}));
   set_weight(1);
   set_value(3520);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   awaters = 0; // regen
   awinds = 0; // haste
   aearth = 0; // stoneskin
   aflames = 0; // heroism
}

int wear_fun() {
   tell_object(ETO,"%^GREEN%^A quiet assurance fills you as you slip the ring onto your finger.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" smiles with an expression of quiet serenity.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You realise you can <invoke> the elements once each day... waters, winds, earth and flames.%^RESET%^");
   TO->set_overallStatus(100);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^GREEN%^You feel a gentle sense of sadness as you remove the ring.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" seems saddened to remove the ring.%^RESET%^",ETO);
   return 1;
}

void init() {
   ::init();
   add_action("invoke_me","invoke");
}

int invoke_me(string str) {
   if(!str) {
     notify_fail("What do you want to invoke?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to wear the ring first.\n");
     return 0;
   }
   if(str != "waters" && str != "winds" && str != "earth" && str != "flames") {
     notify_fail("You can't invoke that.\n");
     return 0;
   } 
   if(str == "waters") {
     if(awaters > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     awaters = time() + 28800;
     new("/cmds/spells/r/_regeneration")->use_spell(ETO,ETO,40,100,"cleric");
     return 1;
   }
   if(str == "winds") {
     if(awinds > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     awinds = time() + 28800;
     new("/cmds/spells/h/_haste")->use_spell(ETO,0,40,100,"bard");
     return 1;
   }
   if(str == "earth") {
     if(aearth > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     aearth = time() + 28800;
     new("/cmds/spells/s/_stoneskin")->use_spell(ETO,ETO,40,100,"mage");
     return 1;
   }
   if(str == "flames") {
     if(aflames > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     aflames = time() + 28800;
     new("/cmds/spells/h/_heroism")->use_spell(ETO,ETO,40,100,"bard");
     return 1;
   }
   notify_fail("Oops, you broke it.\n");
   return 0;	
}

void reset_timer(string str) {
   if(!str) return notify_fail("Reset what?\n");
   if(str = "winds") { awinds = 0; return; }
   if(str = "waters") { awaters = 0; return; }
   if(str = "earth") { aearth = 0; return; }
   if(str = "flames") { aflames = 0; return; }
   return notify_fail("You can't reset that timer.\n");
}

#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int OWNED, tracker, trackerb;
string owner;

void create() {
   ::create();
   set_name("gray boots");
   set_id(({"boots","gray boots","mottled boots","mottled gray boots","boots of teleportation","lesser boots of teleportation"}));
   set_short("%^BOLD%^%^BLACK%^Lesser Boots of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y boots%^RESET%^");
   set_long("These boots are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They are rounded at the toe for greater %^CYAN%^comfort"
"%^RESET%^, and cut high to enclose partway up the wearer's calf. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"soles to prevent any injury to the foot. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the boots "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
   set_lore("An uncommon lesser artifact usually of drow make, these boots "
"allow the wearer to travel by magical means to distant locations. However, "
"this lesser variant of the normal Boots of Teleportation are prone to the "
"regular errors of such magic, sometimes landing the wearer in unfortunate "
"locations.");
   set_property("lore difficulty",12);
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   set_value(1350);
   set_size(2);
   set_ac(0);
   set_property("enchantment",1);
   while(TO->query_property("enchantment")< 1){
      remove_property("enchantment");
      set_property("enchantment",1);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   tracker = 0;
   trackerb = 0;
}

void init() {
   ::init();
   add_action("teleportme","teleportme");
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int wear_fun() {
   if((string)TPQN == owner || avatarp(TP)) return 1;
   tell_object(ETO,"The boots refuse to fit your feet!");
   return 0;
}

int teleportme(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the boots.");
     return 1;
   }
   if(!str) {
     tell_object(TP, "You need to specify somewhere to travel to.");
     return 1;
   }
   if(member_array(str,TP->query_rem_rooms_sort()) < 0 ) {
     tell_object(TP, "You don't have anywhere like that memorized.");
     return 1;
   }
   if(ETP->query_property("no teleport")) {
     tell_object(TP, "There is too much magical interference here.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the power of the boots today.");
     return 1;
   }
   if(trackerb) {
     tracker = time() + 28800;
     trackerb = 0;
   }
   else { trackerb = 1; }
   new("/cmds/wizard/_teleport")->use_spell(TP,str,25);
   return 1;
}

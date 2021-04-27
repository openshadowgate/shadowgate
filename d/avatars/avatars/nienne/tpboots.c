#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int OWNED, charges;
string owner;
void set_my_lore();

void create() {
   ::create();
   set_name("gray boots");
   set_id(({"boots","gray boots","mottled boots","mottled gray boots","boots of teleportation","greater boots of teleportation"}));
   set_short("%^BOLD%^%^BLACK%^Greater Boots of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
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
   set_property("lore difficulty",12);
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   set_value(1350);
   set_size(2);
   set_ac(0);
   set_property("enchantment",3);
   while(TO->query_property("enchantment")< 3){
      remove_property("enchantment");
      set_property("enchantment",3);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   charges = 15+ random(6);
   set_my_lore();
}

void init() {
   ::init();
   add_action("teleportme","teleportme");
}

int wear_fun() {
    if(ETO->query_highest_level() < 35) {
      tell_object(ETO,"You are not experienced enough to use these boots.");
      return 0;
    }
    if(OWNED && owner != (string)TP->query_name() && !avatarp(TP)) {
      tell_object(ETO,"These boots do not belong to you!");
      return 0;
    }
    if(!OWNED && !avatarp(TP)) {
      OWNED = 1;
      owner = (string)TP->query_name();
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The boots fit your feet in unmatched "
"comfort.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" pulls on the "
"comfortable-looking boots.%^RESET%^",ETO);
    return 1;
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
   if(!charges) {
     tell_object(TP,"The boots are depleted of magic.");
     return 1;
   }
   charges--;
   set_my_lore();
   new("/cmds/wizard/_teleport")->use_spell(TP,str,25);
   return 1;
}

void set_my_lore() {
   set_lore("Sir Edward, a noble knight of House Guldwell, is said to first commissioned "
"these enchanted boots.  Sworn to his Lady Mystra to travel the lands and "
"seek out those places where magic's flow ebbed strangely, Sir Edward was "
"content riding the lands on horseback.  But many of those who he was forced "
"to employ in order to solve such problems were not so keen on this form of "
"travel.  In order to facilitate a means by which they could remain at home "
"until needed, Sir Edward sought the aid of the temple's magi to create "
"these boots.  Each was said to be enchanted with the ability to transport "
"one person to a distant location.  This seemed a perfect solution until it "
"became clear that the magic simply could not provide perfect reliability.  "
"After the third member of Sir Edward's team wound up in dangerous places, "
"these boots were abandoned, despite still retaining charges of spell.  In "
"fact, careful study of this set reveals they have "+charges+" charges left.");
}

void renew_charges() { charges = 15+ random(6); }
int is_tazrak_charged() { return 1; }

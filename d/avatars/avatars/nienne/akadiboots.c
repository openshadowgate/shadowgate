#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("boots");
   set_id(({"boots","gray boots","soft boots","soft gray boots","translucent gray boots","translucent boots","boots of the maelstrom","boots of the swirling maelstrom"}));
   set_short("%^WHITE%^%^BOLD%^Boots of the %^BLACK%^M%^WHITE%^a%^CYAN%^e%^WHITE%^l%^BLACK%^s%^WHITE%^t"
"%^CYAN%^r%^WHITE%^o%^BLACK%^m%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^soft gray boots%^RESET%^");
   set_long("%^BLUE%^These boots look rather simple at a glance, made of some sort of %^BLACK%^%^BOLD%^gray "
"cloth%^RESET%^%^BLUE%^ that is particularly soft to the touch.  The underside is re-enforced, but only a "
"little, leaving them not much thicker than the rest of the boots.  There are no laces or buckles to hold the "
"boots on, although they look quite a snug fit already.  Along the outer surface of each is an unique pattern "
"of gentle, %^WHITE%^c%^CYAN%^h%^WHITE%^a%^BLACK%^%^BOLD%^o%^RESET%^%^WHITE%^t%^CYAN%^i%^WHITE%^c%^BLUE%^ "
"whorls across its surface, residual of some strange dying technique.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Little is known of these boots' origins, but many tales tell of the warrior who "
"carried them.  An elf by the name of Khar'hazt found the boots on one of his many travels, and was said to "
"have taken a distinct liking to their rather unique appearance.  For his efforts over the years to aid "
"the temple of Akadi, he was granted by the priesthood to have a blessing bestowed upon them, imbuing them "
"with a powerful enchantment and near supernatural speed.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   set_ac(0);
   set_size(2);
   set_property("enchantment",5);
   set_value(4000);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((int)ETO->query_highest_level() < 30) {
     tell_object(ETO,"A sudden gust of wind pushes you aside, stopping you from wearing the boots!");
     return 0;
   }
   if((string)ETO->query_diety() != "akadi" && !avatarp(ETO)) {
     tell_object(ETO,"A sudden gust of wind pushes you aside, stopping you from wearing the boots!");
     return 0;
   }
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+"'s boots seem to become almost %^RESET%^%^WHITE%^intangible "
"%^BOLD%^as "+ETO->QS+" puts them on.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The boots seem to become almost %^RESET%^%^WHITE%^intangible %^BOLD%^as "
"you wear them.%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^tr%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^nslu%^RESET%^%^WHITE%^c"
"%^BLACK%^%^BOLD%^ent gray boots%^RESET%^");
   set_long("%^BLUE%^These boots seem almost translucent, of a %^BLACK%^%^BOLD%^gentle gray mist "
"%^RESET%^%^BLUE%^that forms a transparent outline around the feet.  The mists seem to move and drift around "
"the feet, as though caught in a gentle breeze.  Throughout the %^BLACK%^%^BOLD%^soft gray colour "
"%^RESET%^%^BLUE%^of each swirls an ever-changing pattern of gentle, %^WHITE%^c%^CYAN%^h%^WHITE%^a"
"%^BLACK%^%^BOLD%^o%^RESET%^%^WHITE%^t%^CYAN%^i%^WHITE%^c%^BLUE%^ whorls, like random lines of smoke or cloud "
"somehow held within their substance.%^RESET%^\n");
   ETO->set_property("magic resistance",10);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+"'s boots become solid again as "+ETO->QS+" removes "
"them.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The boots solidify again as you remove them.%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^soft gray boots%^RESET%^");
   set_long("%^BLUE%^These boots look rather simple at a glance, made of some sort of %^BLACK%^%^BOLD%^gray "
"cloth%^RESET%^%^BLUE%^ that is particularly soft to the touch.  The underside is re-enforced, but only a "
"little, leaving them not much thicker than the rest of the boots.  There are no laces or buckles to hold the "
"boots on, although they look quite a snug fit already.  Along the outer surface of each is an unique pattern "
"of gentle, %^WHITE%^c%^CYAN%^h%^WHITE%^a%^BLACK%^%^BOLD%^o%^RESET%^%^WHITE%^t%^CYAN%^i%^WHITE%^c%^BLUE%^ "
"whorls across its surface, residual of some strange dying technique.%^RESET%^\n");
   ETO->set_property("magic resistance",-10);
   return 1;
}

void init() {
   ::init();
   add_action("whirl_fun","whirl");
}

int whirl_fun() {
   object *weapon,ob;
   if(!TP->is_class("ranger")) return 0;
   if(!random(3)) return 0;

   weapon = TP->query_wielded();
   if((weapon == ({}))) return notify_fail("You should wield your weapons for this!\n");

   if (TP->query_bound() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!(ob = (object)TP->query_current_attacker())) {
      notify_fail("You are not in battle.\n");
      return 0;
   }
   if(TP->query_property("whirled")) return notify_fail("You can't do that again yet");
   if(!TO->query_worn()) return 0;
   tell_room(ETP,"%^WHITE%^%^BOLD%^"+TP->QCN+"'s feet move impossibly fast, as "+TP->QS+" becomes a whirling "
"m%^BLACK%^a%^WHITE%^elst%^CYAN%^r%^BLACK%^om%^WHITE%^ of attacks%^RESET%^",TP);
   tell_object(TP,"%^WHITE%^%^BOLD%^Your boots help you move like the winds of a m%^BLACK%^a%^WHITE%^els"
"%^CYAN%^t%^WHITE%^rom%^WHITE%^, whirling through your foes with numerous attacks!%^RESET%^");
   return 0;
}

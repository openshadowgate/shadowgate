#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("bead");
   set_id(({"bead","shar bead","amethyst bead","bead of amethyst"}));
   set_short("%^RESET%^%^MAGENTA%^flawless bead of ameth%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^st%^RESET%^");
   set_long("%^CYAN%^This single, perfect gem is commonly known as an %^MAGENTA%^amethyst%^CYAN%^.  It has "
"been shaped into a teardrop with step-cut facets, to clearly show the %^MAGENTA%^deep violet %^CYAN%^hue of "
"the stone, reflecting only %^BLACK%^%^BOLD%^darkness%^RESET%^%^CYAN%^ from any light that touches it.  A fine "
"border of %^YELLOW%^gold%^RESET%^%^CYAN%^ metal outlines the gem, so fine that it is nearly invisible.  Such "
"gems are commonly worn upon the brow, attached only by magical means and displayed as a sign of the wearer's "
"status.%^RESET%^\n");
   set_limbs(({"head"}));
   set_weight(0);
   set_value(10);
   set_ac(2);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("enchantment",-1);
   set_property("no steal",1);
   set_property("no offer",1);
   set_property("no animate",1);
}

void init(){
   ::init();
   add_action("wopme_fun","twop");
}

//int drop(){ return 1; }

int wear_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the %^RESET%^%^MAGENTA%^dark power%^BOLD%^%^BLACK%^ of Shar "
"within you as the bead adheres to your forehead.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" gives a %^RESET%^%^MAGENTA%^sini%^BOLD%^%^BLACK%^s%^RESET%^"
"%^MAGENTA%^ter %^BOLD%^%^BLACK%^smile as the bead adheres to "+ETO->QP+" forehead.%^RESET%^",ETO);
   while ((int)TO->query_property("enchantment") != (-1)) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",(-1));
   }
   ETO->set_property("magic resistance",30);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the power of the night recede as you remove the bead.%^RESET%^");
   ETO->set_property("magic resistance",-30);
   return 1;
}

int wopme_fun() {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!avatarp(TP)) return 0;
   if(!TO->query_worn()) return 0;
   if(ETP->is_temple() && (string)ETP->query_diety() == "shar"){
      tell_object(TP,"You are already in your temple!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^Your prayers bring the velvety caress of %^RESET%^%^MAGENTA%^Shar%^BOLD%^"
"%^BLACK%^, who shields you in her darkness as you are spirited away!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A shroud of tangible darkness blossoms into existance, "
"shielding "+TPQCN+" from view.  When the area lightens again, "+TPQCN+" is nowhere to be found!%^RESET%^",TP);
   tell_room(find_object_or_load("/d/magic/temples/shar"),"%^BOLD%^%^BLACK%^A tangible field of darkness "
"coalesces before the altar and solidifies into "+TPQCN+"!%^RESET%^",TP);
   TP->move_player("/d/magic/temples/shar");
   tell_object(TP,"%^BOLD%^%^BLACK%^The blessed caress of %^RESET%^%^MAGENTA%^Shar%^BOLD%^%^BLACK%^ leaves you "
"feeling a strong sense of loss as you appear before her altar.%^RESET%^");
   return 1;
}

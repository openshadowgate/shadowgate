#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("%^RESET%^%^RED%^d%^BOLD%^ee%^RESET%^%^RED%^p cr%^BOLD%^ims%^RESET%^%^RED%^on ves%^BOLD%^tme%^RESET%^%^RED%^nts%^RESET%^");
   set_id(({"robe","robes","crimson vestments","deep crimson vestments","vestments of the black tyrant","vestments"}));
   set_short("%^RESET%^%^RED%^Vestments of the %^BOLD%^%^BLACK%^Bla%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^k T%^RESET%^%^GREEN%^y%^BOLD%^%^BLACK%^rant%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^d%^BOLD%^ee%^RESET%^%^RED%^p cr%^BOLD%^ims%^RESET%^%^RED%^on ves%^BOLD%^tme%^RESET%^%^RED%^nts%^RESET%^");
   set_long("These %^GREEN%^beautiful %^RESET%^vestments could only possibly "
"be the property of nobility, or someone equally wealthy. Sewn from "
"%^CYAN%^fine satin brocade%^RESET%^, the material carries a "
"%^RESET%^%^RED%^r%^BOLD%^ic%^RESET%^%^RED%^h cr%^BOLD%^ims%^RESET%^%^RED%^on "
"h%^BOLD%^u%^RESET%^%^RED%^e%^RESET%^ throughout, only broken by raised "
"embroidery in %^BOLD%^%^BLACK%^jet-black thread%^RESET%^. The threads form "
"well-woven cuffs and hemlines, and mark out the designs of "
"%^BOLD%^%^RED%^fearsome beasts %^RESET%^throughout the rest of the robe - "
"%^BOLD%^%^BLACK%^mighty dragons%^RESET%^, %^ORANGE%^fanged felines%^RESET%^, "
"%^RED%^snarling hellhounds %^RESET%^and other such creatures, all with "
"unusual %^GREEN%^glowing emerald eyes%^RESET%^. Despite that the robe "
"appears to be mere cloth, you can't help but think that you catch glimpses "
"of the creatures moving, as if they were %^BLUE%^alive%^RESET%^.\n");
   set_lore("%^BOLD%^Prized by the faith of Bane, such robes are only ever "
"crafted for his priesthood. Always made from the best of materials, usually "
"silk or satin brocade, they are blessed by a high-ranked priest and often "
"enchanted to appear more impressive than an otherwise mundane robe. "
"Certainly, anyone with enough rank to wear such vestments would be a person "
"not to be trifled with.%^RESET%^");
   set_property("lore difficulty",12);
   set_limbs(({"torso"}));
   set_weight(8);
   set_value(1600);
   set_size(2);
   set_ac(0);
   set_property("enchantment",2);
   while(TO->query_property("enchantment")< 2){
     remove_property("enchantment");
     set_property("enchantment",2);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if(((string)ETO->query_diety() == "bane" && TP->is_class("cleric")) || avatarp(TP)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^You pull the vestments around you, "
"feeling the righteous might of the Black Hand fill you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" seems to become more "
"intimidating as "+ETO->QS+" pulls on the robes.%^RESET%^",ETO);
     ETO->set_property("magic resistance",5);
     return 1;
   }
   tell_object(ETO,"The robes seem not to fit you!");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a strong sense of loss as you "
"remove the robes.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" seems somehow less "
"intimidating after "+ETO->QS+" removes the robes.%^RESET%^",ETO);
   ETO->set_property("magic resistance",-5);
   return 1;
}

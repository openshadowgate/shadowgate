//Updated to bring in line with area difficulty - Octothorpe 4/15/10
//changed by Circe to be mage only on Shar's request - 10/25/03
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wizard's hat");
	set_id(({ "hat", "wizard hat" }));
        set_short("%^BOLD%^%^BLUE%^A blue suede wizard's hat%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This hat is modelled after the classical wizard's hat. The tall conical hat is made out of blue suede. The body of the hat itself is rather soft, allowing it to drape in soft folds, though the point at the top still remains very stiff and straight. A wide brim helps to shield the wearer from the elements and bright lighting. A blue velvet band with a decorative %^RESET%^%^ORANGE%^brass %^BOLD%^%^BLUE%^buckle is set in the center of the hat, where the crown meets the brim.
AVATAR
	);
	set_weight(3);
	set_value(1500);
	set_lore(
@AVATAR
These types of hats are often found among various wizards, who like to dress to impress.  The style of the hat is a classical one, one that every man, woman and child knows.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
      if((TP->is_class("mage")) && (TP->is_class("sorcerer")) && (!TP->is_class("cleric")) && (!TP->is_class("fighter")) && (!TP->is_class("thief"))){
	tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^BOLD%^%^BLUE%^You place the blue suede hat on your head, topping off your wizard's apparel.");
	return 1;
      }
      tell_object(ETO,"The wizard hat refuses to sit right upon your head!");
      return 0;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^BOLD%^%^BLUE%^You remove the blue suede hat, and feel less like a wizard.");
	return 1;
}

void init() {
   ::init();
   if(query_property("enchantment") > 0 && query_property("enchantment") != 3) {
     while(query_property("enchantment") != 3) {
       remove_property("enchantment");
       set_property("enchantment",3);
     }
   }
}
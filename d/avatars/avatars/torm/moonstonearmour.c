#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Moonstone Studded");
	set_id(({ "moonstone studded armour", "moonstone armour", "studded", "armour" }));
	set_short("%^BOLD%^%^WHITE%^Mo%^MAGENTA%^o%^WHITE%^nstone Stu%^CYAN%^d%^WHITE%^ded Leath%^GREEN%^e%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Moonstone Studded Leather%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a suit of studded leather armour.  The be%^MAGENTA%^z%^WHITE%^ainted discs that are secured to the leather with metal studs are made from polished m%^CYAN%^o%^WHITE%^onstone.  This combination of materials helps to keep the armour light and adds a distinctive sheen which is particularly apparant in moonli%^YELLOW%^g%^WHITE%^ht.

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^It is said that over 500 individual moonstone gems were used to create all the discs for this suit of armour, and each one was blessed by the temple of Selune.

AVATAR
	);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The polished gems glimmer in the light as you wear the studded armour.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You polish a couple of the d%^GREEN%^i%^WHITE%^scs when you remove the armour.%^RESET%^");
	return 1;
}

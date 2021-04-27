#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Laced Leaf Armour");
	set_id(({ "laced leaf armour", "laced leaf", "leaf leather", "leaf armour", "armour" }));
	set_short("%^RESET%^%^GREEN%^L%^ORANGE%^a%^GREEN%^c%^RED%^e%^BOLD%^%^GREEN%^d%^RESET%^%^ORANGE%^ L%^GREEN%^e%^RED%^a%^ORANGE%^f %^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^r%^RED%^m%^ORANGE%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^Leaf Armour%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This armour is made of thick fibrous l%^ORANGE%^e%^RED%^a%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^es that have been laced together with %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^eel wire%^RESET%^%^GREEN%^.  Row upon row of leaves have been laced together so that they overap one another.  The steel wire keeps the armour in shape as well as reinforcing  the lea%^ORANGE%^t%^RED%^h%^GREEN%^ery leaves.

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_lore(
@AVATAR
%^GREEN%^The design of this armour has been attirbuted to Hickran Yelso, a ranger of Meilikki.  He observed a young doe seeking protection from the elements beneath the canopy of overlapping braches of a group of trees and cited this as his inspiration.  He sought to emulate the natural instinct of the forest creatures he was dedicated to protecting from harm.

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
	tell_object(ETO,"%^GREEN%^As you wear the laced leaf armour you feel closer to nature.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^You notice the a%^RED%^u%^GREEN%^tum%^ORANGE%^n%^GREEN%^al colours of the leaves as you remove the armour.%^RESET%^");
	return 1;
}

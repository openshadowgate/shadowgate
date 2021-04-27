#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bearskin cloak");
	set_id(({ "cloak", "bearskin" }));
	set_short("%^RESET%^%^ORANGE%^Cloak of the B%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ar%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^bearskin cloak%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a rough cloak, stitched together from the skin of a great brown bear.  The skin of bear's head has been left intact and fashioned into a hood.  The bear's paws and claws form the clasp by which the cloak is held onto the wearer.  The fur is thick and dense, providing protection from attack and the elements.  The skin on the inside of the cloak has been treated so that it is smooth.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1200);
	set_lore(
@AVATAR
The brown bear is becoming rare in this part of the world.  In ages past, their skins were prized for protection, durability and beauty.  The cloak in your hands must be an old and treasured item.


AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" wears the bear cloak, he looks brutal and strong.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You pull on the bear cloak and hood and feel ferocious!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" removes their cloak, they look less savage.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You feel normal again without the cloak.%^RESET%^");
	return 1;
}

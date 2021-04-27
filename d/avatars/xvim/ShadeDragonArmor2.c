#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Red Dragon Scale Armor");
	set_id(({ "armor", "red armor" }));
	set_short("%^RED%^Red Dragon Scale Armor%^RESET%^");
	set_obvious_short("%^RED%^Red leather armor%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This armor is made from hide that has been tanned thoroughly. It is reinforced with close-set red dragon scales. It is somewhat similar to the brigadine armor, except the spacing is wider. It looks designed to absorb the cutting blows of wild thrusts and slashes.

AVATAR
	);
	set_weight(20);
	set_value(500);
	set_lore(
@AVATAR
This armor is made out of the scales of the ancient Red dragon that once resided outside shadow, in the deep desert.

AVATAR
	);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"You wear your strong armor, and feel fit for battle.");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"You remove your strong armor, and feel the cold wind touch your skin.");
	TP->set_property("magic resistance",-5);
	return 1;
}

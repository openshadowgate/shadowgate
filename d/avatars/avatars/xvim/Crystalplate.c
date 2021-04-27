#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^GREEN%^Crystal Plate%^RESET%^");
	set_id(({ "plate", "fullplate", "armor" }));
	set_short("%^GREEN%^The Crystal Plate%^RESET%^");
	set_obvious_short("%^GREEN%^a green plate made out of small crystals%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^The huge plate seems, to be made out of magic and stones, in essense it is thousands upon thousands of small %^GREEN%^green emeralds%^YELLOW%^ placed together into a armor by strong and powerfull magic, it covers the entire body of its owner, and looks immensely impressive.

AVATAR
	);
	set_weight(60);
	set_value(20000);
	set_lore(
@AVATAR
The emerald plate comes from the ogre Headcrusher, who stole it from the gnome miners

AVATAR
	);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",3);
	set_ac(8);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^GREEN%^"+ETO->query_cap_name()+" wears the green plate, and almost seems to meld into the stone.%^RESET%^",TP);
	tell_object(TP,"%^RED%^The %^GREEN%^magic emerald stones%^RED%^ fits around you, and you almost meld into the solid crystals.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^GREEN%^The magical emerald stones seem to loosen from the body of "+ETO->query_cap_name()+".%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^The %^GREEN%^magical emerald stones%^YELLOW%^Loosens from your body, and you feel unprotected.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}

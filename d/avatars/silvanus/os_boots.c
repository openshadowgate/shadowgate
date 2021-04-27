#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Ogre-Skinned Boots");
	set_id(({ "boots", "boot", "ogre-skin boots", "ogre-skin boot", "Ogre-Skin Boots", "Ogre-Skin boot", "ogre skin boots", "Ogre Skin Boots", "ogre skin boot", "Ogre Skin Boot" }));
	set_short("%^RED%^Ogre-Skin Boots%^RED%^");
	set_obvious_short("%^YELLOW%^Wart-covered leather boots%^RESET%^");
	set_long(
@AVATAR
These boots are made from the %^YELLOW%^dried, stretched hide%^RESET%^ of some creature, possibly an ogre.  There outside is covered in leathery %^YELLOW%^warts%^RESET%^ and their inside is padded with a thick, coarse hair.%^RESET%^  

AVATAR
	);
	set_weight(8);
	set_value(100);
	set_type("leather");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+" timidly wears the "+query_short()+"%^YELLOW%^!%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^With a slight hesitance you wear the "+query_short()+"%^YELLOW%^!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+" decides to remove the "+query_short()+"%^YELLOW%^!%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^You decide to remove the "+query_short()+"%^YELLOW%^!%^RESET%^");
	return 1;
}

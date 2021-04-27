#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fingerless gloves");
	set_id(({ "gloves", "glove" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^Finger%^RESET%^%^ORANGE%^less %^BOLD%^%^BLACK%^Gloves%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^finger%^RESET%^%^ORANGE%^less %^BOLD%^%^BLACK%^gloves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a pair of black leather gloves that have been made without fingers.  This type of glove is useful for preserving the natural dexterity of the fingers while still protecting the palm from heat and damage.  The cuffs of the gloves are studded with metal, giving them a fierce appearance.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(900);
	set_lore(
@AVATAR
Fingerless gloves are often used by thieves, horseback riders and pugilists.  Many normal varieties exist, but a few well-made pair have been enchanted by powerful spell-thieves. While the fingerless glove doesn't actually increase one's dexterity, its easier to keep a tight grip on a weapon while wearing them.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^ORANGE%^puts on their gloves and cracks their knuckles loudly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You slip on the gloves and crack your knuckles, feeling pretty tough.%^RESET%^");
	ETO->add_damage_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^ORANGE%^takes of their gloves and doesn't look as tough as before.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You take off the gloves and feel like a wimp.%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}

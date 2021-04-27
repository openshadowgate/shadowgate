#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shield");
	set_id(({ "iron shield", "shield", "circular shield" }));
	set_short("%^RESET%^I%^RED%^r%^BOLD%^%^BLACK%^o%^RESET%^n S%^RED%^t%^BOLD%^%^BLACK%^u%^RESET%^dd%^RED%^e%^RESET%^d S%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^i%^RESET%^eld%^RESET%^");
	set_obvious_short("a large %^BOLD%^%^BLACK%^c%^RESET%^ir%^RED%^c%^BOLD%^%^BLACK%^u%^RESET%^la%^BOLD%^%^BLACK%^r%^RESET%^ shield");
	set_long(
@AVATAR
This large circular shield is made from a sheet of concave %^BOLD%^%^BLACK%^i%^RED%^r%^BLACK%^on %^RESET%^covered in a layer of tough %^BOLD%^%^BLACK%^goat's hide%^RESET%^.  To keep the hide in place, an iron rim has been affixed to the outer edge, pinching down on the plate underneath.  To further secure the shield, rivets have been placed into the front of the shield in the shape of a %^RED%^%^BOLD%^fleur-de-lis%^RESET%^.  A set of leather straps have been affixed to the back to provide a means by which to secure the shield to the lower half of the arm.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(50);
	set_lore(
@AVATAR
Many nations employ shields in order to provide cover and protection to their warriors.  Often these shields are designed with important insignias for the region that they come from.  A fleur-de-lis is used to project a sense of being within the right and having a pure and noble goal.  It has been used throughout the ages by many to project a sense of value and nobility.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("shield");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" appears more confident and ready to take on the world as they strap their "+query_short()+" %^BOLD%^%^RED%^onto their arm!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel a sense of confidence and conviction come over you as you strap the "+query_short()+" %^BOLD%^%^RED%^on and gather up your courage for the fight ahead!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" removes their "+query_short()+" %^BOLD%^%^RED%^ and stretches out their arm, loosening up the joints.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You unbuckle the straps on the back of your "+query_short()+" %^BOLD%^%^RED%^and stretch out your arm to loosen up the joints.%^RESET%^");
	return 1;
}

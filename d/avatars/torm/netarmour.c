#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Netted Leather");
	set_id(({ "netted leather armour", "netted armour", "netted leather", "leather armour", "armour" }));
	set_short("%^RESET%^%^ORANGE%^N%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^tte%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^ Le%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^th%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Netted Leather%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is re-inforced leather armour.  A th%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^n me%^BOLD%^%^WHITE%^t%^RESET%^%^ORANGE%^al m%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^sh ma%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^e of %^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^ithril has been overlayed on the leather, forming a protective outer net for the wearer.  The net has been secured to the leather which is clearly visible beneath it and it is flexible enough to not impede the wearer's movement.

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_lore(
@AVATAR
%^RESET%^%^ORANGE%^Attributed to an Eldathian armoursmith this design encapsulates his vision of harmonious balance in all things.  The Eldathian preferance for the net as a weapon which can incapacitate without injury inspired the use of a net to aid protection also.

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
	tell_object(ETO,"%^RESET%^%^ORANGE%^You are careful not entangle yourself in the net.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You fold the netted leather up neatly.%^RESET%^");
	return 1;
}

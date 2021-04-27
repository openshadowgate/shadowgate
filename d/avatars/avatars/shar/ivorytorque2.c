#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("torque");
	set_id(({ "torque" }));
	set_short("%^RESET%^%^GREEN%^Weathered %^ORANGE%^Copper Torque%^RESET%^");
	set_obvious_short("copper torque");
	set_long(
@AVATAR
%^GREEN%^A thick heavy neck ring made of %^ORANGE%^copper%^GREEN%^.  The copper has been aged to a soft %^WHITE%^silvery %^GREEN%^green color in most spots.  A vine of ivy fashioned out of the metal, wraps around the neck ring.  Detailed leaves have been carved with loving care.  At each end of the torque, two rounded pieces of %^BOLD%^%^WHITE%^ivory%^RESET%^%^GREEN%^ are secured in place.  Carved into each piece of ivory is the head of a unicorn.

AVATAR
	);
	set_weight(5);
	set_value(300);
	set_lore(
@AVATAR
The Copper Torque is seen as a holy blessing by followers of the Lady of the Forest.  

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" %^GREEN%^flashes a big grin.",ETO);
	tell_object(ETO,"%^GREEN%^The soft neigh of a unicorn tickles your ears as you slip on the torque.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" %^GREEN%^slips off his "+query_short()+" %^GREEN%^and pauses to look at it.",ETO);
	tell_object(ETO,"%^GREEN%^You slip off the torque, but notice the images of the unicorns almost seem to wink at you.");
	return 1;
}

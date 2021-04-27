#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("darkness of night");
	set_id(({ "robe" }));
	set_short("a swirling mass of shadows");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This swirling mass of shadows is strange, to say the least.  Every now and then, amidst the shadows, you see pockets of darkness.  The shadows cover the main portion of the wearers torso but otherwise doesn't appear to offer much protection.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"Screams fill the air from seemingly everywhere but then drift away when "+ETOQCN+" is covered in "+query_short()+"",ETO);
	tell_object(ETO,"Screams can be heard from the "+query_short()+" but slowly drift away");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks much more at ease as "+query_short()+" passes through the room",ETO);
	tell_object(ETO,""+query_short()+" covers your eyes momentarily and then clears as they leave the area");
	return 1;
}

#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("gown");
	set_id(({ "gown" }));
	set_short("%^BOLD%^%^BLACK%^Shar's Gown");
	set_obvious_short("A gown woven from pure darkness");
	set_long(
@AVATAR
A gown woven from pure darkness clothes the Mistress of the Night.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_max_internal_encumbrance(1000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",30);
	set_ac(500);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"Shar clothes herself from the darkness in the room",ETO);
	tell_object(ETO,"You cloth yourself with the darkness in the room");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"Shar removes her gown, plunging the room in an unantural darkness",ETO);
	tell_object(ETO,"Your remove your gown, plunging the area into an unnatural darkness");
	return 1;
}

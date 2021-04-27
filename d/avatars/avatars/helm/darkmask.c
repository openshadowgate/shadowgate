#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("mask");
	set_id(({ "mask", "dark mask" }));
	set_short("%^BOLD%^%^BLACK%^a solid dark mask%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a solid dark mask%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This mask is made of an odd lightweight metal colored in a solid black hue. It sports the non-descript facial features of an infant with rounded cheeks, large dark eyes and a faint smile set upon the lips. The inside of the mask is lined with felt for comfort.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(165);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You don the mask with a feeling of discomfort as it seems to merge with your face.%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^For a second fear washes you over as you cannot find out how to remove the mask.%^RESET%^");
	ETO->set_property("magic resistance",-10);
	return 1;
}

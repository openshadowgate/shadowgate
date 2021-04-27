#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gentle gloves");
	set_id(({ "gloves", "glove", "gentle glove", "gentle gloves" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^Gentle Gl%^BLACK%^o%^WHITE%^ves%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^soft white gloves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a pair of soft white gloves, sewn from high quality bleached linen.  They are perfectly clean and silky smooth to the touch.  A single, %^BLACK%^black%^ %^WHITE%^button on each glove fits them neatly onto each hand.  They are the perfect accessory for a gentle man or lady, and match almost anything.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(200);
	set("chabonus",1);
	set_type("clothing");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^BOLD%^%^WHITE%^slips on their lovely gloves.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^WHITE%^You slip the gloves on smoothly and they fit perfectly.%^RESET%^");
	ETO->set_property("magic resistance",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^BOLD%^%^WHITE%^removes their gloves, losing a touch of class.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^WHITE%^You feel less fancy without your gloves.%^RESET%^");
	ETO->set_property("magic resistance",-2);
	return 1;
}

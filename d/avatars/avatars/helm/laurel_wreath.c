#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("laurel wreath");
	set_id(({ "wreath", "laurel", "laurel wreath" }));
	set_short("%^RESET%^%^GREEN%^la%^BOLD%^urel wre%^RESET%^%^GREEN%^ath%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^la%^BOLD%^urel wre%^RESET%^%^GREEN%^ath%^RESET%^");
	set_long(
@AVATAR
This is a simple circlet of laurel foliage worn on the head.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}



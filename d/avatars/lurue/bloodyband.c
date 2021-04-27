#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloth strip");
	set_id(({ "cloth strip", "strip", "bloody cloth" }));
	set_short("%^BLUE%^a strip of dark & %^RED%^stained%^BLUE%^ cloth%^RESET%^");
	set_obvious_short("%^BLUE%^a strip of dark & %^RED%^stained%^BLUE%^ cloth%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^This is a silken piece of material that's been soaked in %^RED%^BLOOD!%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
}



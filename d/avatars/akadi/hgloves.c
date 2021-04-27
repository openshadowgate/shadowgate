#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^long back gloves%^RESET%^");
	set_id(({ "gloves" }));
	set_short("%^BOLD%^%^BLACK%^Long Bl%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ck Gloves%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^long black gloves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These gloves are crafted from thin black leather that has been polished to a high shine. They are very long, extending up to the wearer's shoulders. They seem quite supple, allowing free movement of the fingers and arms.%^RESET%^


AVATAR
	);
	set_weight(5);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
}



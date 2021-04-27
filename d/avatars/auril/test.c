#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("test");
	set_id(({ "rubber nose" }));
	set_short("%^BOLD%^%^RED%^A bright rubber nose %^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A bright rubber nose %^RESET%^");
	set_long(
@AVATAR
Ha.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(9);
}



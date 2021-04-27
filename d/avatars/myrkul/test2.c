#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("test2");
	set_id(({ "boot" }));
	set_short("boot");
	set_obvious_short("boot");
	set_long(
@AVATAR
boot

AVATAR
	);
	set_weight(5);
	set_value(10);
	set("conbonus",1);
	set_type("clothing");
	set_limbs(({ "right foot" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
}




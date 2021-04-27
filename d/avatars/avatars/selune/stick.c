#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("stickthingie");
	set_id(({ "stick" }));
	set_short("Stick thingie");
	set_obvious_short("Stick thingie");
	set_long(
@AVATAR
This is a stick!

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",5);
	set_type("bludgeoning");
	set_prof_type("clublike");
	set_size(2);
	set_wc(2,4);
	set_large_wc(3,6);
	set_property("enchantment",2);
}



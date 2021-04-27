#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("busted sword");
	set_id(({ "sword", " broken sword", " busted sword", " crappy sword", " busted" }));
	set_short("Busted Sword");
	set_obvious_short("sword");
	set_long(
@AVATAR
THis sword is broken, but still useable until you can find something better.

AVATAR
	);
	set_weight(5);
	set_value(5);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",0);
}



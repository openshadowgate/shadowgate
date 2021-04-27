#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bastard sword");
	set_id(({ "sword", "bastardsword", "bastard sword", "blade", "weapon" }));
	set_short("An old bastard sword");
	set_obvious_short("An old bastard sword");
	set_long(
@AVATAR
This is an old bastard sword, rusty and stuff...

AVATAR
	);
	set_weight(20);
	set_value(115);
	set_property("lore difficulty",);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",1);
}



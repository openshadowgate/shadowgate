#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cotton robe");
	set_id(({ "robe" }));
	set_short("%^RESET%^%^ORANGE%^tan cotton robe%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a simple tan robe that seems to be made of well combed and woven cotton.  It has been crafted in a style common to Tsarven, meant to fold over itself, then to be held in place by a sash or belt.  The cloth is light, and looks like it would be comfortable in an arid environment.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(15);
	set_lore(
@AVATAR
This robe is nothing terribly special, but was probably crafted by the Tsarvani.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}



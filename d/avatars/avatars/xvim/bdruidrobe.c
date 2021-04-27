#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Blue druid robe");
	set_id(({ "robe", "armor", "blue robe" }));
	set_short("%^BLUE%^A dark blue druid robe");
	set_obvious_short("%^BLUE%^A dark blue druid robe");
	set_long(
@AVATAR
%^BLUE%^This blue druids robe, is a long sleeved hooded robe, that goes all the way to the ground, covering all but the face. it looks pretty common except of the color.

AVATAR
	);
	set_weight(15);
	set_value(500);
	set_lore(
@AVATAR
The blue robes are for special type of druids**

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
}



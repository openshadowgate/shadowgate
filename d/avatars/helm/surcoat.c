#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("surcoat");
	set_id(({ "surcoat" }));
	set_short("A surcoat");
	set_obvious_short("A surcoat");
	set_long(
@AVATAR
This is a surcoat

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}



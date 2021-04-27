#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("robe");
	set_id(({ "robe" }));
	set_short("robe");
	set_long(
@AVATAR
this is a robe to test armor

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(4);
	set_value(1);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}



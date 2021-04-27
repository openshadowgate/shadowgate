#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("basic dagger");
	set_id(({ "dagger", " basic dagger" }));
	set_short("A dagger");
	set_obvious_short("This is a dagger to test the item2 command");
	set_long(
@AVATAR

AVATAR
	);
	set("read",
@AVATAR
You can't read this.

AVATAR
	);
	set_weight(2);
	set_value(2);
	set_lore(
@AVATAR
No legends available.

AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",1);
}



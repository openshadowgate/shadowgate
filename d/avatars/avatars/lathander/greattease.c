#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("The Great Tease");
	set_id(({ "dagger", "great tease", "The Great Tease", "Great Tease", "tease", "Tease", "your mom" }));
	set_short("A big hulky dagger");
	set_obvious_short("A big hulky dagger");
	set_long(
@AVATAR
Nanananananananananana! You cannot have this!

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("piercing");
	set_prof_type("dagger");
	set_size(1);
	set_wc(1,20);
	set_large_wc(1,20);
	set_property("enchantment",15);
	set_ac(99);
}



#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("staff for shar");
	set_id(({ "staff" }));
	set_short("a short staff");
	set_obvious_short("staff");
	set_long(
@AVATAR
This is a Short Test staff**

AVATAR
	);
	set_weight(5);
	set_value(500);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(2);
	set_wc(2,5);
	set_large_wc(3,5);
	set_property("enchantment",3);
	set_ac(0);
}



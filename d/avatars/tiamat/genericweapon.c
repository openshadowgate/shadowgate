#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("weapon");
	set_id(({ "weapon" }));
	set_short("weapon");
	set_obvious_short("weapon");
	set_long(
@AVATAR
This item is for immortal use only.  If you should find it, please offer immediately.  Thank you.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(20,2);
	set_large_wc(20,2);
	set_property("enchantment",4);
}




#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("santaboots");
	set_id(({ "boots" }));
	set_short("%^BOLD%^%^BLACK%^Black leather boots%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Black leather boots%^RESET%^");
	set_long("This is a a pair of very polished leather boots with silver buckles.
");
	set_value(0);
	set_size(2);
	set_property("enchantment",4);
}




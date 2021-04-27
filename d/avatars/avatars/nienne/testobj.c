#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("testobj");
	set_id(({ "cloak", "cape" }));
	set_short("long cape");
	set_obvious_short("long cape");
	set_long("It's a very long pretty cape.
.
");
	set_value(1);
	set_size(2);
	set_property("enchantment",1);
}




#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("testy");
	set_id(({ "testy", " longsword" }));
	set_short("this is a test");
	set_obvious_short("test sword");
	set_long("test sword to see if this works.
");
	set_value(10);
	set_lore("hades is so awesome
");
	set_property("lore difficulty",10);
	set_item_bonus("wisdom",1);
	set_item_bonus("magic resistance",1);
	set_property("enchantment",1);
}




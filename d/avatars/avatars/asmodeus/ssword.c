#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("testsword");
	set_id(({ "sword", "longsword" }));
	set_short("this is a sword");
	set_obvious_short("sword!!");
	set_long("this is a big sword
");
	set_value(10000000);
	set_item_bonus("healing",40);
	set_property("enchantment",8);
}




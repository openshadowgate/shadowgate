#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("elfhat");
	set_id(({ "hat" }));
	set_short("%^RESET%^%^GREEN%^A greenish pointed hat%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A greenish pointed hat%^RESET%^");
	set_long("This is a small pointed greenish hat
");
	set_value(0);
	set_item_bonus("damage resistance",30);
	set_item_bonus("magic resistance",2);
	set_size(1);
	set_property("enchantment",5);
}




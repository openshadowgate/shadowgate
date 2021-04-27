#include <std.h>
inherit "/d/common/obj/armour/shield";

void create(){
	::create();
	set_name("npc_cloud");
	set_id(({ "cloud", "shield", "shadows" }));
	set_short("%^BOLD%^%^BLACK%^a cloud of teeming shadows%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a cloud of teeming shadows%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a mass of menacing, jagged shadows that swirls about its host like a tangle of hungry snakes, seeming to dart out and strike at anything near to it.%^RESET%^
");
	set_value(0);
	set_lore("OOC: If you're reading this, you should not have this. Please offer this item. :)
");
	set_property("lore difficulty",0);
	set_item_bonus("dexterity",4);
	set_item_bonus("constitution",4);
	set_item_bonus("wisdom",4);
	set_size(2);
	set_property("enchantment",10);
}




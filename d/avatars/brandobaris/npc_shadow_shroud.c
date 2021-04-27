#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("npc_shroud");
	set_id(({ "shroud", "armor", "shadows" }));
	set_short("%^BOLD%^%^BLACK%^a shroud of ragged shadows%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a shroud of ragged shadows%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a mass of menacing, jagged shadows that swirls about its host like a tangle of hungry snakes, seeming to dart out and strike at anything near to it.%^RESET%^
");
	set_value(0);
	set_lore("OOC: If you're reading this, you should not have this. Please offer this item. :)
");
	set_property("lore difficulty",0);
	set_item_bonus("armor bonus",40);
	set_item_bonus("attack bonus",20);
	set_item_bonus("damage bonus",15);
	set_item_bonus("reflex",4);
	set_item_bonus("will",4);
	set_item_bonus("fortitude",4);
	set_size(2);
	set_property("enchantment",10);
}




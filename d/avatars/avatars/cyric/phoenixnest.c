#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("rocks");
	set_id(({ "mound", "nest", "rocks", "stones", "pile", "pile of rocks", "pile of stones", "phoenix nest", "stone nest", "rock nest", "mound", "mound of stones", "mound of rocks", "rock pile" }));
	set_short("Mound of Rocks");
	set_obvious_short("Mound of Rocks");
	set_long(
@AVATAR
This is a pile of rocks ranging in size from pebbles to small stones, all together roughly 18 inches off the ground, and three feet in diameter.  At the top of the pile, there is a small depression perhaps 10 inches across.

AVATAR
	);
	set_weight(500);
	set_value(0);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(5);
	set_property("enchantment",0);
}



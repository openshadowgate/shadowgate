#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("rubble pile");
	set_id(({ "rubble", "pile" }));
	set_short("%^RESET%^%^ORANGE%^a rubble pile%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a rubble pile%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a large rubble pile full of broken rocks and skeletal remains, old weapons, armor and even a little treasure, if you dare brave to search around in it.%^RESET%^

AVATAR
	);
	set_weight(200);
	set_value(0);
	set_max_internal_encumbrance(300);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",0);
}



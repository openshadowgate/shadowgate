#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gloves of the shinobi");
	set_id(({ "gloves" }));
	set_short("%^BOLD%^%^BLACK%^gloves of the shinobi%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Black gloves%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This pair of gloves is surrounded by an shadowy substance. The substance, which is the make up of shadows themselves, surrounds the glove and dance along it constantly. Wrapping themselves around the wearers forearm, they seem very comfortable.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(2500);
	set("strbonus",2);
	set("dexbonus",2);
	set_type("clothing");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
}




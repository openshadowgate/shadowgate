#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("lunarrobe");
	set_id(({ "robe", "lunar robe" }));
	set_short("%^BLUE%^Lunar%^RESET%^%^BOLD%^ Robe%^RESET%^");
	set_obvious_short("%^BLUE%^Lunar%^RESET%^%^BOLD%^ Robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^This robe is made of the finest velvet which has been dyed a %^BLUE%^royal blue color.%^RESET%^%^BOLD%^  The sleeves and collar have been embroidered with %^BOLD%^%^BLACK%^silver%^RESET%^%^BOLD%^ thread in an intricate design.  The robe is long, ending just at the wearer's ankles. A %^BOLD%^%^BLACK%^silver cord%^RESET%^%^BOLD%^ wraps around the wearer's waist allowing them to keep the robe tied around their body.

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}



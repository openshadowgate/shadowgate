#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("reed sandals");
	set_id(({ "sandals", "reed sandals" }));
	set_short("%^RESET%^%^ORANGE%^reed sandals%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Long strands of dried reed have been smoothed and woven together to form small cords.  These cords are bound together in such a way that they form a simple platform.  A few strips of leather have been added to tie around the wearer's ankles and keep the sandals in place.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5);
	set_lore(
@AVATAR
These sandals don't seem to bear any specific story, but are more common among the people of Tsarven.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}



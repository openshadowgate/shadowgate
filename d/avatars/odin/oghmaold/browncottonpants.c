#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("brown pants");
	set_id(({ "pants", "brown pants", "brown cotton pants" }));
	set_short("%^RESET%^%^ORANGE%^A pair of brown cotton pants%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A pair of brown cotton pants%^RESET%^");
	set_long(
@AVATAR
These are a set of relatively simple cotton pants which have been dyed a rich, deep %^RESET%^%^ORANGE%^brown%^RESET%^.  They appear to fall to the average wearers ankles and have been tailored loosely to allow freedom of movement.  They are held onto the wearer by means of a %^BOLD%^%^BLACK%^black belt %^RESET%^that runs along the top of them.  In contrast to their simple design, these pants are well-made and in extroardinary condition.

AVATAR
	);
	set_weight(2);
	set_value(1000);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",1);
}



#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("claw");
	set_id(({ "claw", "claws" }));
	set_short("%^RESET%^%^ORANGE%^razor sharp claw%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^razor sharp claw%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^These are claws worn by a mob.  They are for immortal use only.  If this item should find itself into your grubby hands, please offer it.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("claw");
	set_size(1);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",0);
}




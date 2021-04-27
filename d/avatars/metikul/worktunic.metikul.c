#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Work tunic");
	set_id(({ "tunic", " work tunic" }));
	set_short("Work tunic");
	set_obvious_short("leather tunic");
	set_long(
@AVATAR
A leather tunic made out of hide of some animal.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
	set_weight(25);
	set_value(200);
	set_max_internal_encumbrance(20);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(2);
}



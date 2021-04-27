#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Istishia sucks");
	set_id(({ "sword", "Sword" }));
	set_short("Istishia sucks");
	set_obvious_short("Istishia sucks");
	set_long(
@AVATAR
Istishia sucks

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(10,1);
	set_large_wc(10,1);
	set_property("enchantment",0);
	set_ac(0);
}



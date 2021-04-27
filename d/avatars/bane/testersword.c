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
Istishia sucks a big fat one.

AVATAR
	);
	set("read",
@AVATAR
Istishia still sucks.

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
It is said that Istishia sucks, and sucks a lot.

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(2);
	set_wc(10,1);
	set_large_wc(10,1);
	set_property("enchantment",0);
	set_ac(0);
}



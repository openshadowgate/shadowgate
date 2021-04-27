#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Troll loin cloth");
	set_id(({ "cloth" }));
	set_short("a old smelly loin cloth");
	set_obvious_short("a old smelly loin cloth");
	set_long(
@AVATAR
This is the loin cloth roc uses to cover his private parts

AVATAR
	);
	set_weight(100);
	set_value(500);
	set_lore(
@AVATAR


AVATAR
	);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(3);
	set_property("enchantment",2);
	set_ac(4);
}



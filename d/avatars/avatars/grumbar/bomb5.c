#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Amateur IED");
	set_id(({ "bomb", "ied", "explosive" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^a metal %^RESET%^pipebomb");
	set_obvious_short("%^RESET%^a metal cylinder");
	set_long(
@AVATAR
testing

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
testing

AVATAR
	);
	set_property("lore difficulty",21);
	set_type("piercing");
	set_prof_type("tool");
	set_size(1);
	set_wc(1,100);
	set_large_wc(1,100);
	set_property("enchantment",0);
}



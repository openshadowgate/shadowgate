#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Wooden stakes for Vampire");
	set_id(({ "stake", "wood", "wooden stake" }));
	set_short("%^ORANGE%^Wooden Stake%^RESET%^");
	set_obvious_short("%^ORANGE%^Wooden Stake%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This medium thick piece of wood, is carved to a point in one end, it is normally used by vampire hunters to kill the evil Vampires

AVATAR
	);
	set_weight(5);
	set_value(1);
	set_lore(
@AVATAR
It is an ancient item used for generations to destroy the undead vampires

AVATAR
	);
	set_type("piercing");
	set_prof_type("Wooden Stake");
	set_size(1);
	set_wc(1,3);
	set_large_wc(1,3);
	set_property("enchantment",0);
}



#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("axe of revenge");
	set_id(({ "axe", "revenge", " axe of revenge" }));
	set_short("%^BOLD%^Axe of revenge%^RESET%^");
	set_obvious_short("axe");
	set_long(
@AVATAR
This is a finely crafted axe. Its detailed design and fine edge, would prove worthy against the ost well armored opponent.

AVATAR
	);
	set_weight(7);
	set_value(500);
	set_lore(
@AVATAR
The axe of revenge is one that will end its will to revenge.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium axe");
	set_size(2);
	set_wc(2,4);
	set_large_wc(3,4);
	set_property("enchantment",4);
}



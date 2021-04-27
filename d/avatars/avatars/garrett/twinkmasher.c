#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("twinkmasher 2000");
	set_id(({ "twinkmasher 2000", "twinkmasher" }));
	set_short("Twink Masher 2000");
	set_obvious_short("Heavy Mallet");
	set_long(
@AVATAR
This is a long, heavy mallet carved with fell runes of power.

AVATAR
	);
	set("read",
@AVATAR
If you need instructions...

AVATAR
	);
     set("langage","str");	set_weight(10);
	set_value(0);
	set_lore(
@AVATAR
Smite twinks down with this artifact.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("large hammer");
	set_size(4);
	set_wc(10,10);
	set_large_wc(10,10);
	set_property("enchantment",20);
}



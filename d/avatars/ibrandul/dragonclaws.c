#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^black claws%^RESET%^");
	set_id(({ "claws" }));
	set_short("%^BLACK%^%^BOLD%^black claws%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black claws%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_type("slashing");
	set_prof_type("claws");
	set_size(3);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
}



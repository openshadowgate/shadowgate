#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("sealed letter");
	set_id(({ "letter", "sealed letter" }));
	set_short("%^BOLD%^%^BLUE%^A sealed letter%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A sealed letter%^RESET%^");
	set_long(
@AVATAR
This is a piece of fine %^RESET%^%^ORANGE%^parchment %^RESET%^that has been folded letter style and sealed with wax.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}
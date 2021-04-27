#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of rum");
	set_id(({ "rum", "bottle", "rum bottle", "bottle of rum" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^BLUE%^rum%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^BLUE%^rum%^RESET%^");
	set_long(
@AVATAR
This is a glass bottle filled with a white %^BOLD%^%^BLUE%^rum%^RESET%^.  It has been corked carefully and sealed with wax.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of wine");
	set_id(({ "wine", "bottle", "wine bottle", "bottle of wine" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of %^RESET%^%^MAGENTA%^wine%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of %^RESET%^%^MAGENTA%^wine%^RESET%^");
	set_long(
@AVATAR
This is a glass bottle filled with %^RESET%^%^MAGENTA%^red wine%^RESET%^.  It has been corked carefully and sealed with wax.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
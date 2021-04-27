#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of moonshine");
	set_id(({ "moonshine", "bottle", "moonshine bottle", "bottle of moonshine" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^BLACK%^moonshine%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^BLACK%^moonshine%^RESET%^");
	set_long(
@AVATAR
This is a glass bottle filled with homeade %^BOLD%^%^BLACK%^moonshine%^RESET%^.  It has been corked carefully and sealed with wax.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
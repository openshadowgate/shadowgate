#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of vodka");
	set_id(({ "vodka", "bottle", "vodka bottle", "bottle of vodka" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^WHITE%^vodka%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of %^BOLD%^%^WHITE%^vodka%^RESET%^");
	set_long(
@AVATAR
This is a glass bottle filled with %^BOLD%^%^WHITE%^vodka%^RESET%^.  It has been corked carefully and sealed with wax.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
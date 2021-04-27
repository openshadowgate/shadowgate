#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of whiskey");
	set_id(({ "whiskey", "bottle", "whiskey bottle", "bottle of whiskey" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of %^RESET%^%^RED%^whiskey%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of %^RESET%^%^RED%^whiskey%^RESET%^");
	set_long(
@AVATAR
This is a glass bottle filled with sour mash %^BOLD%^%^RED%^whiskey%^RESET%^.  It has been corked carefully and sealed with wax.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
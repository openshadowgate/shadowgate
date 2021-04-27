#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar of oregano");
	set_id(({ "jar", "oregano", "oregano jar", "jar of oregano" }));
	set_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^%^ORANGE%^oregano%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^%^ORANGE%^oregano%^RESET%^");
	set_long(
@AVATAR
This is a regular quality glass jar filled with aromatic dried oregano leaves.  It has been sealed with wax to keep it fresh.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
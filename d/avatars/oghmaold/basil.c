#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar of basil");
	set_id(({ "jar", "basil", "basil jar", "jar of basil" }));
	set_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^%^ORANGE%^basil%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^%^ORANGE%^basil%^RESET%^");
	set_long(
@AVATAR
This is a regular quality glass jar filled with aromatic dried basil leaves.  It has been sealed with wax to keep it fresh.

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_property("lore difficulty",0);
}
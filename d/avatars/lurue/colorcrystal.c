#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("crystal orb");
	set_id(({ "orb", "crystal orb" }));
	set_short("%^BOLD%^%^WHITE%^a small crystal orb%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a small crystal orb%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This little crystal is no bigger then a child's fist, but is oddly colored, never seemingly the same color regardless of how you look at it.  Like quartz it seems clear with rainbow highlights, yet as you focus, it takes on an ever shifting band of coloring.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(20);
	set_lore(
@AVATAR
The serathel stones are known for their ability to alter colors under the will of the one holding them.  Often used by children being trained as psionists, they are considered a child's bobble.

AVATAR
	);
	set_property("lore difficulty",10);
}
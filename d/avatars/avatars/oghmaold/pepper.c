#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar of pepper");
	set_id(({ "jar", "pepper", "pepper jar", "jar of pepper" }));
	set_short("%^BOLD%^%^WHITE%^A glass jar filled with %^BOLD%^%^BLACK%^pepper%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A glass jar filled with %^BOLD%^%^BLACK%^pepper%^RESET%^");
	set_long(
@AVATAR
This is a regular quality glass jar filled with aromatic ground peppercorns.  It has been sealed with wax to keep it fresh.

AVATAR
	);
	set_weight(5);
	set_value(25);
	set_property("lore difficulty",0);
}
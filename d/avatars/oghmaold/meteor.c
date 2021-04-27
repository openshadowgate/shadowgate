#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("meteor");
	set_id(({ "meteor" }));
	set_short("%^BOLD%^%^RED%^A fiery hot meteor%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A fiery hot meteor%^RESET%^");
	set_long(
@AVATAR
This is a fallen meteor.  It is composed of rock, though a large metallic vein of the purest mithril you have ever seen runs through it.

AVATAR
	);
	set_weight(50);
	set_value(5000);
	set_property("lore difficulty",0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("salt jar");
	set_id(({ "salt", "jar", "salt jar", "jar of salt" }));
	set_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^salt%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A glass jar filled with %^RESET%^salt%^RESET%^");
	set_long(
@AVATAR
This is a regular quality glass jar filled with salt.  It has been sealed with wax to keep it fresh.

AVATAR
	);
	set_weight(5);
	set_value(50);
	set_property("lore difficulty",0);
}
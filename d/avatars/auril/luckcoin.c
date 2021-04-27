#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("luck coin");
	set_id(({ "coin" }));
	set_short("%^BOLD%^%^YELLOW%^Tymora's %^BOLD%^%^RED%^B%^BOLD%^%^YELLOW%^lessing%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A small coin%^RESET%^");
	set_long(
@AVATAR
This small gold coin has two symbols of Tymora on either side of it. It is made out of pure %^BOLD%^%^YELLOW%^gold, and crafted to perfection. 

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This small coin was given out to priests of Tymora many years ago. The tradition has since faded, but those who had them that long ago would never give them up willingly as they are said to carry the luck of the Goddess with it.

AVATAR
	);
	set_property("lore difficulty",30);
}
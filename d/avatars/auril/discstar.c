#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("star disc");
	set_id(({ "disc" }));
	set_short("%^BOLD%^%^RED%^Disc of the Stars%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A small circular disc");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This small circular disc seems to be oddly out of place. On the surface of the disc is a bright %^BOLD%^%^YELLOW%^star %^BOLD%^%^WHITE%^which shines. 

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This is part of the Box of Eternity.

AVATAR
	);
}
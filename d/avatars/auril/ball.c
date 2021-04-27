#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ball");
	set_id(({ "ball" }));
	set_short("%^BOLD%^%^BLUE%^Sphere of the Wo%^BOLD%^%^YELLOW%^rld%^RESET%^%^BOLD%^%^BLUE%^s");
	set_obvious_short("A small ball");
	set_long(
@AVATAR
This is a small ball, which looks to have tiny stars inside, floating about.

AVATAR
	);
	set_weight(1);
	set_value(0);
}
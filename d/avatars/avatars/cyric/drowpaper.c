#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("parchment");
	set_id(({ "parchment", "paper", "scroll" }));
	set_short("Scroll");
	set_obvious_short("scroll");
	set_long(
@AVATAR
This is a scroll, perhaps you can read it.

AVATAR
	);
	set("read",
@AVATAR
Powdered gashyl moss had no effect whatsoever, its like there is no magic contained in it at all.  I am sure this is the proper one, and it is only a matter of time before I unlock it.

AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(1);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("horse hide");
	set_id(({ "hide", " horse hide" }));
	set_short("horse hide");
	set_obvious_short("horse hide");
	set_long(
@AVATAR
Expertly skinned hide of a fine charger.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
	set_weight(25);
	set_value(100);
}
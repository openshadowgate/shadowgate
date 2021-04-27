#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("child");
	set_id(({ "child", "baby" }));
	set_short("A small baby");
	set_obvious_short("A small baby");
	set_long(
@AVATAR
This is a small baby, crying and covered with dirt, but still alive.

AVATAR
	);
	set_weight(10);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("head");
	set_id(({ "head" }));
	set_short("a female head");
	set_obvious_short("a female head");
	set_long(
@AVATAR
This is the head of a female. She looks to have chaotic looking curls in her hair with beads in it in many places.

AVATAR
	);
	set_weight(5);
	set_value(0);
}
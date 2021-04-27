#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tcorpse");
	set_id(({ "corpse" }));
	set_short("the corpse of a half-drow");
	set_obvious_short("the corpse of a half-drow");
	set_long(
@AVATAR
This is the corpse of a half-drow, laying upon the altar, brutally battared and damaged by fire.

AVATAR
	);
	set_weight(400);
	set_value(0);
}
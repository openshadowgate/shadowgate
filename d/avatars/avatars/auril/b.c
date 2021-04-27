#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("blood");
	set_id(({ "blood" }));
	set_short("A pool of blood that streaks across the room");
	set_obvious_short("A pool of blood that streaks across the room");
	set_long(
@AVATAR
This is a large puddle of blood that is streaked through the mud as if someone was dragged.

AVATAR
	);
	set_weight(5000);
	set_value(0);
}
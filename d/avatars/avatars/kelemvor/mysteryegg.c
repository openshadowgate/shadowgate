#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("A mysterious egg");
	set_id(({ "egg" }));
	set_short("A mysterious looking egg. It is about the size of an ostritch egg, and has dark purple spots on it.");
	set_obvious_short("A large and mysterious egg");
	set_long(
@AVATAR
A mysterious looking egg. It is about the size of an ostritch egg, and has dark purple spots on it.

AVATAR
	);
	set_weight(1);
	set_value(0);
}
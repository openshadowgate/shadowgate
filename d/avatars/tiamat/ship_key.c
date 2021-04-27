#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ship key");
	set_id(({ "ship key", "key" }));
	set_short("The Ship Key");
	set_obvious_short("A wood and brass key on a chain");
	set_long(
@AVATAR
This brass key's handle is highly decorated in a seashell motif along the handle made of hardwood.

AVATAR
	);
	set_weight(1);
	set_value(0);
}
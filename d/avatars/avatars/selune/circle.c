#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("circleofchalk");
	set_id(({ "circle", "chalk circle", "circle of chalk" }));
	set_short("circle");
	set_obvious_short("circle");
	set_long(
@AVATAR
This is a perfectly drawn circle of chalk.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}
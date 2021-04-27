#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Circle of Chalk");
	set_id(({ "circle", "chalk circle", "circle of chalk" }));
	set_short("Circle of Chalk");
	set_obvious_short("Circle of Chalk");
	set_long(
@AVATAR
This is a perfectly drawn circle of chalk.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",go to findecano);
}
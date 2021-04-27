#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("piece");
	set_id(({ "cloth", "piece", "piece of robe" }));
	set_short("A piece of robe");
	set_obvious_short("A piece of robe");
	set_long(
@AVATAR
This looks to be a piece of a robe obviously torn. I wonder who's it is?

AVATAR
	);
	set_weight(1);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("burning ship");
	set_id(({ "ship" }));
	set_short("This is the wreckage of a burning ship");
	set_obvious_short("This is the wreckage of a burning ship");
	set_long(
@AVATAR
This looks to be the wreckage of a burning ship. Fire still licks up a bit.

AVATAR
	);
	set("read",
@AVATAR
l

AVATAR
	);
     set("langage","common");	set_weight(3000);
	set_value(0);
	set_lore(
@AVATAR
l
w
echoto kinson You see something at the docks.




AVATAR
	);
}
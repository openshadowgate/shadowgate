#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jail key");
	set_id(({ "key", "jail key" }));
	set_short("an iron jail key");
	set_long(
@AVATAR
This key is made of iron which makes it very strong.  Several cuts and protrusions extend along its end making a complex network of switches for the tumblers in the locks.  On the other end a simple clover patern has been shaped to allow the key to be turned easily.

AVATAR
	);
	set_weight(1);
	set_value(0);
}
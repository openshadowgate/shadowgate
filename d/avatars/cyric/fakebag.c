#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("fake comp bag");
	set_id(({ "component bag", "leather bag", "bag", "comp bag", "fake bag", "fake comp bag", "fake components bag" }));
	set_short("A leather bag");
	set_obvious_short("A leather bag");
	set_long(
@AVATAR
This looks like an ordinary mage's components bag, but you can see that there is no opening for it to hold any components.  There is a small note attached to the bottom of the bag, maybe you should read the bag?

AVATAR
	);
	set("read",
@AVATAR
Congratulations, you are dead.

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(1);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ear");
	set_id(({ "ear", "elven ear" }));
	set_short("%^RESET%^%^ORANGE%^an elven ear%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^an elven ear%^RESET%^");
	set_long(
@AVATAR
This is a delicately shaped elven ear. It has been removed from the head with a clean cut and the blood has been washed away. It appears to have been treated with something as to keep in good shape.

AVATAR
	);
	set_weight(1);
	set_value(0);
}
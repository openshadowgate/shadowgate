#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("key castle");
	set_id(({ "key", "castle key", "key castle" }));
	set_short("iron castle key");
	set_obvious_short("iron castle key");
	set_long(
@AVATAR
This is a key made from rough iron.  It is rusting slightly with age.  Hopefully, it still works.

AVATAR
	);
	set_weight(1);
	set_value(1);
}

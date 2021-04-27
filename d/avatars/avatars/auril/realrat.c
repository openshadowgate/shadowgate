#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rat");
	set_id(({ "rat" }));
	set_short("A small, friendly rat");
	set_obvious_short("A small, friendly rat");
	set_long(
@AVATAR
This is a small friendly rat, of the variety found in Torm.  It has bright, happy eyes that shine with intellgience.  Occasinally, it makes strange sounds.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(0);
}
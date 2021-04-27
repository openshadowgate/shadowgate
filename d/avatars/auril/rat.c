#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rat");
	set_id(({ "rat" }));
	set_short("A little mechanical rat");
	set_obvious_short("A little mechanical rat");
	set_long(
@AVATAR
This little mechanical rat moves about on little steel wheels. It seems to be going around fairly nimbly and obviously outmoving its maker.

AVATAR
	);
	set_weight(2);
	set_value(5);
}
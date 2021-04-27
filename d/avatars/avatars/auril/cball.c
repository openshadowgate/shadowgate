#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("crystal balls");
	set_id(({ "ball" }));
	set_short("A crystal ball");
	set_obvious_short("A crystal ball");
	set_long(
@AVATAR
This is a seemingly ordinary crystal ball, perfectly round with a small wooden base.

AVATAR
	);
	set_weight(5);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("A big ass rock");
	set_id(({ "rock" }));
	set_short("A big ass rock");
	set_obvious_short("A big ass rock");
	set_long(
@AVATAR
A big ass rock

AVATAR
	);
	set_weight(0);
	set_value(0);
}
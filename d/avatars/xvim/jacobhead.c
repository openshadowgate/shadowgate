#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("head of jacob");
	set_id(({ "head" }));
	set_short("The head of Jacob");
	set_obvious_short("The head of Jacob");
	set_long(
@AVATAR
This is the head of Jacob.

AVATAR
	);
	set_weight(2);
	set_value(0);
}
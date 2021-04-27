#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("red");
	set_id(({ "portal" }));
	set_short("%^BOLD%^%^RED%^A glowing portal");
	set_obvious_short("%^BOLD%^%^RED%^A glowing portal");
	set_long(
@AVATAR
A glowing portal that looks to only go one way, you cannot enter it.

AVATAR
	);
	set_weight(500);
	set_value(0);
}
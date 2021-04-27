#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^a small wooden cork%^RESET%^");
	set_id(({ "cork", "wooden cork" }));
	set_short("%^RESET%^%^ORANGE%^a small wooden cork%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a small wooden cork%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a small wooden cork, perfect for shoving into holes.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(1);
}
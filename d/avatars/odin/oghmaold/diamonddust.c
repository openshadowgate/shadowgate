#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("diamond dust");
	set_id(({ "pouch", "dust", "diamond dust" }));
	set_short("%^RESET%^%^ORANGE%^A large pouch of diamond dust%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A large pouch of diamond dust%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a mid sized leather pouch full of the finest diamond dust.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(100000);
	set_property("lore difficulty",0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a blue key");
	set_id(({ "key", "blue key" }));
	set_short("%^BOLD%^%^BLUE%^A blue key%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A blue key%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^A blue key, probably used somewhere in this keep.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
}
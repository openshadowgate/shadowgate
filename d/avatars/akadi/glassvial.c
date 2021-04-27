#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^A glass vial%^RESET%^");
	set_id(({ "vial", "bottle" }));
	set_short("%^BOLD%^%^BLUE%^A crystal vial filled with liquid%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A crystal vial filled with liquid%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is a crystal vial filled with a clear liquid%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(4);
}
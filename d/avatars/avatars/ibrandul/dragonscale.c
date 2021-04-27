#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^dragon scales%^RESET%^");
	set_id(({ "scales", "dragon scales" }));
	set_short("%^BLACK%^%^BOLD%^dragon scales%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^dragon scales%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^dragon scales ripped from the body of what looks like a mature dragon, many armorsmiths would kill for material like this%^RESET%^

AVATAR
	);
	set_weight(30);
	set_value(100000);
}
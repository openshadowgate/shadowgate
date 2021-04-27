#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^dragon fangs%^RESET%^");
	set_id(({ "fangs", "dragon fangs" }));
	set_short("%^RESET%^%^BOLD%^dragon fangs%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^dragon fangs%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^dragon fangs, ripped from the mouth of a dragon. Many things could be made, and many weaponsmiths would love to get thier hands on somthing like these%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(50000);
}
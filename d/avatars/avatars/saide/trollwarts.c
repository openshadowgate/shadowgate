#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("warts");
	set_id(({ "warts", "troll warts", "wart", "troll wart" }));
	set_short("%^BOLD%^%^GREEN%^Leathery troll warts%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^Leathery troll warts%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^These large warts have been removed from a troll by fire.  There texture is leathery and they give off a very powerful and foul odor.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("obsidian stone");
	set_id(({ "stone", "obsidian stone" }));
	set_short("%^BOLD%^%^BLACK%^Ob%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^dian S%^WHITE%^t%^RESET%^o%^BOLD%^%^BLACK%^ne%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Ob%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^dian S%^WHITE%^t%^RESET%^o%^BOLD%^%^BLACK%^ne%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a crystal clear, completely perfect piece of obsidian shaped into a solid orb.  It weighs quiet a bit and is stunning to look upon.  Near depthless when it is gazed upon, the quality would be rare to find and make it quite expensive.

AVATAR
	);
	set_weight(20);
	set_value(5000);
}
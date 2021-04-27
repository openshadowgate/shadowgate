#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ferret");
	set_id(({ "ferret", "white ferret", "fuzzy brown ferret" }));
	set_short("%^BOLD%^%^WHITE%^A %^YELLOW%^fuzzy %^WHITE%^white ferret%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^YELLOW%^fuzzy %^WHITE%^white ferret%^RESET%^");
	set_long(
@AVATAR
This ferret is a rodent-like mammal that appears to be approximately eighteen inches in length.  It has %^BOLD%^%^WHITE%^fuzzy white fur %^RESET%^that covers its entire body.  However its face is a stark contrast: %^BOLD%^%^BLACK%^black fur %^RESET%^that is remiscient of a mask.  It has a set of typical rodent ears that stand atop its sleek head.  A pair of beady, %^BOLD%^%^BLACK%^black %^RESET%^eyes peer out from its face and scan over its surroundings.  This one appears to be quite friendly and intelligent.

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
}
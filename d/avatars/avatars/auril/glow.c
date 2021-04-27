#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("glow");
	set_id(({ "glow", "light", "aura" }));
	set_short("%^BOLD%^%^YELLOW%^A soft glowing light raises from the altar to the ceiling over items%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^A soft glowing light raises from the altar to the ceiling over items%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This pillar of light shines down on a handful of items. 

AVATAR
	);
	set_weight(350);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Mask of Death");
	set_id(({ "mask", "mask of death", "death mask" }));
	set_short("%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^sk of De%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^th%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_long(
@AVATAR
This mask is made of stainless titanium. The mask is in the shape of an expressionless face. Their are no openings in the mask. Where the eyes on the mask are, two obsidian gems sit. On the inside of the mask there is some small writing. You do not understand how the wearer of the mask is supposed to see through the it, much less put it on.

AVATAR
	);
	set_weight(5);
	set_value(2000);
}
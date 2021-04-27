#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("onyx block");
	set_id(({ "block", "onyx" }));
	set_short("An ugly, squat %^BOLD%^%^BLACK%^block of onyx %^RESET%^chained to a %^BOLD%^%^WHITE%^marble pedestal%^RESET%^");
	set_obvious_short("An ugly, squat %^BOLD%^%^BLACK%^block of onyx %^RESET%^chained to a %^BOLD%^%^WHITE%^marble pedestal%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A solid bock of onyx, about the size of an ogre's head, shaped into an irregular rectangle. The edges are rounded and blunted, the curves of them flowing downwards like part-molten wax. On closer inspection, it appears that it may be a box of some description. A faint line around the top looks suspiciously like a lid, and there are a couple of notches at the back which could be hinges. The top of a large, %^RESET%^%^RED%^dull redy ruby %^BOLD%^%^BLACK%^can be seen in the lid, the surrounding onyx almost covering, as if the gem has sunk into the surrounding stone like a victim into quicksand. A single, %^BOLD%^%^GREEN%^elaborate green sigil %^BOLD%^%^BLACK%^has been inscribed on the front of the box.

AVATAR
	);
	set_weight(10);
	set_value(0);
}
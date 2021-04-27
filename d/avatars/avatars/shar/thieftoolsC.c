#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("case of tools");
	set_id(({ "tools", "thief's tools", "case of tools" }));
	set_short("%^RESET%^%^ORANGE%^A soft leather case of tools%^RESET%^");
	set_long(
@AVATAR
This is a small, soft %^ORANGE%^leather case%^RESET%^ that can be rolled and tied closed with %^ORANGE%^leather thongs%^RESET%^.  The case, when fully opened, reveals rows of pouches and slots filled with one %^YELLOW%^enchanted key%^RESET%^ with numerous sliding rods, %^CYAN%^long metal picks %^RESET%^and %^BLUE%^pries%^RESET%^.  A few vials of %^GREEN%^acid%^RESET%^ are included, to aid in any stubborn locks.  These tools would probaly aid any locksmith.

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
These locksmith tools are often carried by rogues who need to find more delicate ways around locks than bashing or breaking them open.  This master's set is one that only the rare rogue are seen with,  usually those who teach others their craft.

AVATAR
	);
	set_property("lore difficulty",13);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("figurine");
	set_id(({ "knight", "figurine", "onyx knight" }));
	set_short("%^BOLD%^%^BLACK%^An onyx knight%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^An onyx knight%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a small statue of a knight that has been carved from a piece of solid onyx.  It has been chiseled to an exact likeness of a knight decked out completely in full plate armor and wielding a massive two handed sword out in front of it.  There is a single word written near the base of it.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Summon %^CYAN%^Armonolis%^RESET%^ with all caution.

AVATAR
	);
     set("langage","elven");	set_weight(10);
	set_value(1000);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a wooden toolbox");
	set_id(({ "box", "toolbox", "wooden toolbox", "piaf's toolbox" }));
	set_short("%^RESET%^%^ORANGE%^A tiny wooden toolbox%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This small wooden box has a hinged lid that may be opened and a %^YELLOW%^brass handle%^RESET%^%^ORANGE%^.  Inside are stored many different %^RESET%^tools%^ORANGE%^, all of which seem too small for a human to use.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Property of Piaf Hufflemuffin

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(25);
}
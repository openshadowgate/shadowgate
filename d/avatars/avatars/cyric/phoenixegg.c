#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("egg");
	set_id(({ "egg", "phoenixegg", "phoenix egg", "omlette", "silver egg", "silveregg" }));
	set_short("%^RESET%^%^BOLD%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^ E%^RESET%^g%^BOLD%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^ E%^RESET%^g%^BOLD%^g%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This is a sparkling silver egg, about three inches in diameter.  It is warm to the touch.  While it appeared to be made of silver at first glance, on closer inspection it is clearly not metal or stone, but something organic.
%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
There's nothing on it to read.

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(50000);
	set_lore(
@AVATAR
This is the egg of a legendary creature known as a phoenix.  These birds of flame are said to be immortal, and their eggs are said to be useful for certain types of magical rituals.

AVATAR
	);
	set_property("lore difficulty",15);
}
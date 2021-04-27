#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^wooden flute decorated with %^BOLD%^%^BLUE%^f%^RESET%^%^BLUE%^e%^GREEN%^a%^BOLD%^%^GREEN%^th%^RESET%^%^GREEN%^e%^BLUE%^r%^BOLD%^s%^RESET%^");
	set_id(({ "flute", "wooden flute" }));
	set_short("%^RESET%^%^ORANGE%^wooden flute decorated with %^BOLD%^%^BLUE%^f%^RESET%^%^BLUE%^e%^GREEN%^a%^BOLD%^%^GREEN%^th%^RESET%^%^GREEN%^e%^BLUE%^r%^BOLD%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^wooden flute decorated with %^BOLD%^%^BLUE%^f%^RESET%^%^BLUE%^e%^GREEN%^a%^BOLD%^%^GREEN%^th%^RESET%^%^GREEN%^e%^BLUE%^r%^BOLD%^s%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Delicately carved from a smooth piece of wood, this is a simple looking flute with 12 holes. The wood has been smoothed down and polished to a %^RESET%^dull %^ORANGE%^shine. Running your fingers over the wood reveals almost impossibly tiny, %^GREEN%^s%^ORANGE%^tr%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ng%^GREEN%^e%^ORANGE%^ %^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^u%^ORANGE%^n%^GREEN%^e%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^ carved into the surface. Two %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^en%^RESET%^%^ORANGE%^ and two %^BOLD%^%^BLUE%^bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e %^RESET%^%^BLUE%^fe%^GREEN%^a%^BOLD%^%^GREEN%^th%^RESET%^%^GREEN%^e%^BLUE%^rs%^RESET%^%^ORANGE%^ dangle from the end of the flute, tied to thin strips of leather. The wood is remarkably %^RED%^w%^ORANGE%^ar%^RED%^m%^ORANGE%^ to the touch and seems to be quite sturdy.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2000);
}
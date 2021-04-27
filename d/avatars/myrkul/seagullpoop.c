#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Seagull Poop");
	set_id(({ "poop", "seagull poop" }));
	set_short("%^BOLD%^%^GREEN%^F%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^w%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^ S%^BLUE%^e%^WHITE%^agull %^GREEN%^P%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^op%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^F%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^w%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^ S%^BLUE%^e%^WHITE%^agull %^GREEN%^P%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^op%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This a foul smelling %^BOLD%^%^WHITE%^seagull%^RESET%^%^ORANGE%^ dropping. These birds are renowned for their accuracy of their droppings. Some cities are known to put bounties on t"
	"he shitbirds.%^RESET%^
"
	);
	set_value(0);
	set_weight(0);
}

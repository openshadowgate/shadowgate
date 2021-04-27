#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^dino turd%^RESET%^");
	set_id(({ "turd", " dino turd" }));
	set_short("%^RESET%^%^ORANGE%^Gigantic dino turd%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Gigantic dino turd%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This giant turd is the size of a small boulder. It has all kinds of partially digested grasses and pinecones in it. It smells terrible! %^BOLD%^%^MAGENTA%^Gross!%^RESET%^
");
	set_value(0);
	set_weight(10);
}

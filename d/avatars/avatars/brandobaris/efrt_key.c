#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("cell key");
	set_id(({ "key", "cell key", "steel key" }));
	set_short("%^BOLD%^%^BLACK%^a sturdy s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^l key%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a sturdy s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^l key%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This simple-looking %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^e%^RESET%^l %^BOLD%^%^BLACK%^key is about eight inches long in length, and its handle is wrapped in %^RESET%^%^ORANGE%^tanned "
	"leather%^BOLD%^%^BLACK%^. A few %^RESET%^%^GREEN%^elven runes %^BOLD%^%^BLACK%^seem to be inscribed onto its side, but they are almost too faint to read.%^RESET%^
"	);
	set_value(0);
	set_weight(0);
}

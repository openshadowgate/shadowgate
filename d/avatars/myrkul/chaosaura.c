#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_id(({ "aura" }));
	set_short("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_long("%^BOLD%^%^RED%^This %^BLACK%^hazy%^RED%^ pocket of air seems to %^RESET%^%^BLUE%^s%^BOLD%^c%^RESET%^%^CYAN%^r%^BOLD%^a%^GREEN%^m%^RESET%^%^GREEN%^b%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^RE"
	"D%^ everything that passes under its %^YELLOW%^entropic%^RED%^ domain. A perpetual source of chaos, the presence sucks the order out of everything around it. At times flowers bloom or wither out of se"
	"ason right before your eyes. Knots untie and re-tie themselves. Works of art are distorted, with straight lines never to be seen again. The %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^"
	"GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^RED%^ is centered on a single shard of %^WHITE%^bone%^RED%^ and might be worn around the neck.%"
	"^RESET%^
"
	);
	set_value(10000);
	set_lore("The %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^ grants youth to its wearer by transferri"
	"ng the disorder of the body to the environment. Maintaining ones sanity while living in a chaos field would require a person of great wisdom. Of course, a person of great wisdom might not necessarily "
	"want to wear an %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^. The history of the Aura and"
	" its creator is Murky at best, with various sects of %^BOLD%^%^CYAN%^Tymora%^RESET%^, %^MAGENTA%^Beshaba%^RESET%^, and %^BOLD%^%^BLACK%^Cyric%^RESET%^ claiming it at various times. The Aura is conside"
	"red a holy relic by clergy of all three deities, with warfare and murder sprees to get it back from a competing sect.
"
	);
    set_property("lore difficulty",30);
	set_heart_beat(1);

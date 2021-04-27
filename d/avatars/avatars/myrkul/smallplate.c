#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("plate");
	set_id(({ "plate", "armor" }));
	set_short("%^BOLD%^%^BLUE%^S%^RESET%^%^BLUE%^k%^BOLD%^y S%^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^%^BLUE%^e%^BOLD%^l P%^RESET%^%^BLUE%^l%^BOLD%^a%^RESET%^%^BLUE%^t%^BOLD%^e%^RESET%^");
	set_obvious_short("%^BLUE%^blue-tinged fullplate%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This is a %^MAGENTA%^miniature%^BLUE%^ set of full plate armor. Strangely it is made out of a %^CYAN%^bluish metal%^BLUE%^ that must be some kind of %^RESET%^%^BLUE%^cobalt%^BOLD%^. It"
	" looks as if it was made for some kind of gnome or small child. An emblem of an %^GREEN%^airship%^BLUE%^ is an embossed on the center plate.%^RESET%^
"
	);
	set_value(10000);
	set_lore("This armor is made out of some kind of alloyed cobalt or steel. It is a rare set of armor made for gnomish warriors that ride in Airships. These warriors fought in many expeditions for gnomes, and the"
	" armor has gotten a reputation for its extreme strength and light weight. Nevetheless, airships are few and far between, and this kind of armor is not well known in the lands.
"
	);
    set_property("lore difficulty",15);
	set_size(2);
	set_property("enchantment",2);
}




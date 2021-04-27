#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("belt");
	set_id(({ "belt" }));
	set_short("%^BOLD%^%^CYAN%^Gladiator Belt of the Fourth Circle%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^Gladiator Belt of the Fourth Circle%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This belt is made of a fine leather. The buckle is of solid %^WHITE%^silver%^BLACK%^ embellished with a symbol of %^YELLOW%^crossed swords over a field of five circles%^RESET%^.
");
	set_value(1000);
	set_lore("Only a Gladiator holds such a belt. They are the standard belt of Gladiators worn across the lands. It is the required rank to get into provincial competitions. The silver buckles are somewhat valuabl"
	"e, but it is the feat to have earned such a belt that is what gives these belts their notoriety. 
"
	);
    set_property("lore difficulty",0);
	set_size(2);
	set_property("enchantment",1);
}




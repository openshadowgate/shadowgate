#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("belt");
	set_id(({ "belt" }));
	set_short("%^BOLD%^%^BLUE%^Gladiator Belt of the Sixth Circle%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^Gladiator Belt of the Sixth Circle%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This belt is made of a fine leather. The buckle is of solid %^CYAN%^platinum%^BLACK%^ embellished with a symbol of %^YELLOW%^crossed swords over a field of six circles%^RESET%^.
");
	set_value(1000);
	set_lore("Only a highly successful Gladiator holds such belts. They are coveted by the few who have heard of them, and the fewer still that have seen them. The platinum buckles are extremely valuable, but it is"
	" the feat to have earned such a belt that is what gives these belts their notoriety.
"
	);
    set_property("lore difficulty",0);
    set("strbonus",1);
	set_size(2);
	set_property("enchantment",2);
}




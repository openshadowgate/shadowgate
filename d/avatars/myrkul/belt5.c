#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("belt");
	set_id(({ "belt" }));
	set_short("%^BOLD%^%^RED%^Gladiator Belt of the Fifth Circle%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Gladiator Belt of the Fifth Circle%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This belt is made of a fine leather. The buckle is of solid %^YELLOW%^gold%^BLACK%^ embellished with a symbol of %^YELLOW%^crossed swords over a field of five circles%^RESET%^.
");
	set_value(1000);
	set_lore("Only a professional Gladiator holds such a belt. They are coveted by many in the Gladiator arenas across the lands. It is usually the required rank to get into major competitions. The gold buckles are"
	" extremely valuable, but it is the feat to have earned such a belt that is what gives these belts their notoriety. 
"
	);
    set_property("lore difficulty",0);
    set("strbonus",1);
	set_size(2);
	set_property("enchantment",1);
}




#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("belt");
	set_id(({ "belt" }));
	set_short("%^BOLD%^%^WHITE%^Gladiator Belt of the Third Circle%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Gladiator Belt of the Third Circle%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This belt is made of a fine leather. The buckle is of solid %^RESET%^%^ORANGE%^copper%^BOLD%^%^BLACK%^ embellished with a symbol of %^YELLOW%^crossed swords over a field of three circ"
	"les%^RESET%^.
"
	);
	set_value(1000);
	set_lore("Aspiring Gladiators wear these belts, and it is the minimum rank at which one might call himself or herself a gladiator. The copper buckles are virtually worthless, but it is enough so that other glad"
	"iators might recognize someone as one of their own. Lesser fodder such as beasts or slaves are not even worth recognition. 
"
	);
    set_property("lore difficulty",0);
	set_size(2);
	set_property("enchantment",0);
}




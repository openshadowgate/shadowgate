#include <std.h>
inherit "/d/common/obj/weapon/giant_bastard";

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Giant Wrought Iron Sword%^RESET%^");
	set_id(({ "sword", "giant sword" }));
	set_short("%^BOLD%^%^BLACK%^Giant Wrought Iron Sword%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Giant Wrought Iron Sword%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This oversized sword is fit for a giant. It looks enormously heavy and is made out of solid iron. The hilt is rapped with leather and it looks as dull as a butter knife. Of course, ge"
	"tting hit with it is sure to leave an impression.%^RESET%^
"
	);
	set_value(1000);
	set_lore("This sword was forged by Oxglak, the Bugbear Barbarian for his raids. Only a giant could wield such a blade.

Its probably not a great weapon but the sheer audacity of its wielder has left it memorabl"
	"e to the wise.
"
	);
    set_property("lore difficulty",0);
	set_property("enchantment",3);
}




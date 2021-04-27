#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Necklace");
	set_id(({ "necklace" }));
	set_short("%^ORANGE%^A wooden Necklace with a %^RED%^ruby%^RESET%^");
	set_obvious_short("%^ORANGE%^A wooden Necklace with a %^RED%^ruby%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This well-detailed piece of craftwork is carved from oak and shaped to look like a spiked gauntlet. Clenched in the palm of the gauntlet is a precisely-cut, large %^RED%^ruby%^YELLOW%^, red as blood. The oak is finely polished to protect it from wear and tear and it dangles off a heavy platinum %^WHITE%^chain%^YELLOW%^, which can be worn around the wearer's neck. Neatly carved into the bottom of the gauntlet are the small initials %^RESET%^"%^GREEN%^A.A%^RESET%^"%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_type("ring");
	set_limbs(({ }));
	set_size();
	set_property("enchantment",0);
	set_ac(0);
}



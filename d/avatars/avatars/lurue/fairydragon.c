#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fairy dragon pin");
	set_id(({ "pin", "fairy dragon pin" }));
	set_short("%^BOLD%^%^BLUE%^F%^MAGENTA%^a%^WHITE%^i%^BLUE%^ry D%^YELLOW%^r%^WHITE%^a%^BLUE%^g%^MAGENTA%^o%^BLUE%^n P%^MAGENTA%^i%^BLUE%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a little pin%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This little pin has a F%^MAGENTA%^a%^WHITE%^i%^BLUE%^ry D%^YELLOW%^r%^WHITE%^a%^BLUE%^g%^MAGENTA%^o%^BLUE%^n on it.  It can be worn on a lapel or cloak.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^Always trust in Luck%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(10);
	set_lore(
@AVATAR
Sometimes luck favors the bold, and often people carry little items to remind them of such times.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",0);
}



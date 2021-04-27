// updated to new equipment system. Nienne, 5/15.
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armband");
	set_id(({ "armband" }));
	set_short("%^BOLD%^%^CYAN%^A%^WHITE%^r%^CYAN%^m%^WHITE%^b%^CYAN%^a%^WHITE%^n%^CYAN%^d%^WHITE%^ of the C%^CYAN%^r%^WHITE%^e%^CYAN%^s%^WHITE%^c%^CYAN%^e%^WHITE%^nt %^BLACK%^M%^CYAN%^o%^BLACK%^on%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^s%^BOLD%^h%^RESET%^%^BLUE%^imm%^BOLD%^e%^RESET%^%^BLUE%^ring a%^BOLD%^r%^RESET%^%^BLUE%^mba%^BOLD%^n%^RESET%^%^BLUE%^d%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This armband seems to %^BLACK%^s%^BLUE%^w%^CYAN%^i%^BLACK%^r%^BLUE%^l%^CYAN%^ in the light. It is made out of a fine %^GREEN%^silk%^CYAN%^ fabric, with a beautifully embroidered %^BLACK%^crescent moon%^CYAN%^. The armband is clearly a mark of some long forgotten %^RED%^military%^CYAN%^ order.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(1000);
	set_lore("%^BOLD%^%^WHITE%^An order of %^YELLOW%^rogues%^WHITE%^, %^RESET%^%^CYAN%^freebooters%^BOLD%^%^WHITE%^, and %^RESET%^%^MAGENTA%^gypsies%^BOLD%^%^WHITE%^ came together in the wilds on the coast of Torm. Dedicated to the defense against incursions from both tyrannical soldiers of Tonovi and the underdark, "
"these followers of %^BLUE%^Selune%^WHITE%^ wandered the inlets and bays springing ambushes and harrying any evil creatures preying on hapless travellers. While the %^CYAN%^Wanderers of the Crescent Moon%^WHITE%^ are all but forgotten, their mark of brotherhood survives them to aid those that guard against %^BLACK%^darkness.%^RESET%^");
	set_property("lore difficulty",20);
	set_item_bonus("dexterity",2);
	set_type("ring");
	set_limbs(({ "left hand","right hand" }));
	set_size(-1);
	set_property("enchantment",1);
}




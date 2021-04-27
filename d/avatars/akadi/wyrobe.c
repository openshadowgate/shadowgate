#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^RESET%^A simple g%^BOLD%^%^BLACK%^ra%^RESET%^y r%^BOLD%^%^BLACK%^o%^RESET%^be");
	set_id(({ "robe" }));
	set_short("%^RESET%^A simple g%^BOLD%^%^BLACK%^ra%^RESET%^y r%^BOLD%^%^BLACK%^o%^RESET%^be");
	set_obvious_short("%^RESET%^A simple g%^BOLD%^%^BLACK%^ra%^RESET%^y r%^BOLD%^%^BLACK%^o%^RESET%^be");
	set_long(
@AVATAR
%^RESET%^This robe looks very warm. The thick folds of cloth could easily protect anyone from the elements and it seems to posses a waterproof quality to keep out the damper weather. It has been dyed a non-assuming shade of %^BOLD%^%^BLACK%^li%^RESET%^g%^BOLD%^%^BLACK%^ht g%^RESET%^ra%^BOLD%^%^BLACK%^y%^RESET%^ and bears no decoration except for the neckline and sleeves, which have been lined with %^RESET%^%^MAGENTA%^vi%^BOLD%^ol%^RESET%^%^MAGENTA%^et v%^BOLD%^e%^RESET%^%^MAGENTA%^lv%^BOLD%^e%^RESET%^%^MAGENTA%^t%^RESET%^. The pockets bulge out heavily, as if they might burst open at any given moment.

AVATAR
	);
	set_weight(10);
	set_value(2000);
	set_max_internal_encumbrance(500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}



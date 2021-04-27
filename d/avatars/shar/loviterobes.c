#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("robes");
	set_id(({ "robes" }));
	set_short("%^BOLD%^%^BLACK%^Vestments of %^RED%^Loviatar%^RESET%^");
	set_obvious_short("robes");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These robes have been fashioned from a high grade of linen.  They have been dyed a rich deep shade of black.  Inside the robes is a brilliant %^RED%^crimson%^BLACK%^ satin lining.  Stitched into the linen are nine strands of a whip.  You can see that the deail on the whip strands are immaculant.  You can make out each barb on the whips in the deep %^RED%^blood red%^BLACK%^ thread.  The whips run from bottom to top, so that the the ends of the whip details end about mid chest

AVATAR
	);
	set("read",
@AVATAR
robes

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_lore(
@AVATAR
The Vestments of Loviatar are given to those of her faith who have taken the charge of Loviatar to heart and strike fear and pain in everyone
(**

AVATAR
	);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}



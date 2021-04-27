#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Cloak of Enlightenment");
	set_id(({ "cloak" }));
	set_short("%^BOLD%^%^BLACK%^Cloak of%^RESET%^%^CYAN%^ Enlightenment%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black cloak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This full-length cloak is made from black satin with an interior of %^RESET%^%^YELLOW%^bronze colored silk%^BOLD%^%^BLACK%^.  The collar is high and stiff and is fastened together by an eye sculpted of %^RESET%^%^YELLOW%^bronze%^BOLD%^%^BLACK%^.  The cloak itself looks as though it is fairly light in weight.  In the center of the back of the cloak is a %^RESET%^%^CYAN%^cyan eye%^BOLD%^%^BLACK%^ with an %^CYAN%^aquamarine pupil%^BLACK%^ which has been embroidered using some sort of %^RESET%^shiny%^BOLD%^%^BLACK%^ thread along with %^RESET%^diamonds,%^CYAN%^ blue topaz, %^BOLD%^%^BLACK%^and %^CYAN%^aquamarine%^RESET%^ gems.  %^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^eye%^RESET%^ sparkles %^BOLD%^%^BLACK%^and %^RESET%^shimmers%^BOLD%^%^BLACK%^ as a result when the light hits it.  Over all, the cloak appears to be that which you'd find a nobleman wearing at a formal gathering.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(60000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^This is the cloak that was presented as a gift to Auppenser when his first temple was christened.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",30);
	set_ac(50);
}



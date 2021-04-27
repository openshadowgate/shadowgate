#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lunar Sword");
	set_id(({ "sword", "longsword", "long sword", "lunar sword" }));
	set_short("%^CYAN%^L%^BLUE%^u%^CYAN%^n%^BLUE%^a%^CYAN%^r%^RESET%^ %^BOLD%^%^YELLOW%^Sword%^RESET%^");
	set_obvious_short("%^CYAN%^L%^BLUE%^u%^CYAN%^n%^BLUE%^a%^CYAN%^r%^RESET%^ %^BOLD%^%^YELLOW%^Sword%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This long sword is double-edge and extremely sharp.  The blade is tapered and has a blood groove on both sides.  The hilt is encrusted with %^BLUE%^moon stones%^RESET%^.  %^CYAN%^This sword is truly beautiful.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(1200);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(medium);
	set_wc(2,6);
	set_large_wc(2,4);
	set_property("enchantment",2);
}



#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jewelry");
	set_id(({ "gem", "jewelry", "chain" }));
	set_short("%^RESET%^a %^GREEN%^mar%^BOLD%^vello%^RESET%^%^GREEN%^us %^YELLOW%^g%^BOLD%^e%^YELLOW%^m%^RESET%^ on a %^BOLD%^%^BLACK%^sil%^RESET%^ver cha%^BOLD%^%^BLACK%^in%^RESET%^");
	set_obvious_short("%^RESET%^a %^GREEN%^mar%^BOLD%^vello%^RESET%^%^GREEN%^us %^YELLOW%^g%^BOLD%^e%^YELLOW%^m%^RESET%^ on a %^BOLD%^%^BLACK%^sil%^RESET%^ver cha%^BOLD%^%^BLACK%^in%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}



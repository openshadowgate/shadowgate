#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Dagger of Orlytyl");
	set_id(({ "dagger" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^a plain steel gray dagger%^RESET%^");
	set_obvious_short("a small dagger");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This dagger is plain in appearance.  The blade is cold, dull gray steel.  The handle is wrapped in the tendon of some poor soul.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(small);
	set_wc(3,20);
	set_large_wc(3,100);
	set_property("enchantment",10);
	set_ac(0);
}



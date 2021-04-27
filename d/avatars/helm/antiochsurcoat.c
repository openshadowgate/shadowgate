#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("surcoat");
	set_id(({ "surcoat", "coat" }));
	set_short("%^RESET%^%^BOLD%^Silver Surcoat%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^Silver Surcoat%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This surcoat has been crafted from a gray cotton and has been woven with threads of silver, to give it added protection as well as a silver glow. The image of a pegasus flying above a shield has been woven into the front with silver threads, the sign of Antioch's man-at-Arms.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
}



#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Hooded Velvet Cloak%^RESET%^");
	set_id(({ "cloak" }));
	set_short("%^BOLD%^%^BLACK%^Hooded Velvet Cloak%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Hooded Velvet Cloak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This sensuous cloak feels and looks exquisite against the flesh. The weightless folds of the soft velvet accent the curve of the wearer's form. A large black hood can be raised to leave conceal the face in shadows.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(2);
}



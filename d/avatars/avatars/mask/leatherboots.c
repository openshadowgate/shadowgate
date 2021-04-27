#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Sturdy Boots");
	set_id(({ "boots", "leather boots", "sturdy leather boots", "sturdy boots" }));
	set_short("%^RESET%^%^ORANGE%^Mi%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^er's Foo%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^gear%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Sturdy Leather Boots%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a pair of sturdy and heavy leather boots.  They seem to be shaped in a squarish manner, and have a thick sole to match.  They appear to be made of a very thick leather which seems rather stiff, but quite protective.  Faint scuffmarks mar the leather in places, but any aging doesn't appear to have damaged the boots severely.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(150);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(1);
	set_property("enchantment",1);
}



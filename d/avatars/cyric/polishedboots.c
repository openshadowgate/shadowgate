#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("black boots");
	set_id(({ "boots", " leather boots", " polished boots", " black boots" }));
	set_short("%^RESET%^%^BLACK%^%^BOLD%^Black Boots%^RESET%^");
	set_obvious_short("Black Boots");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^These are a pair of smartly polished black boots.  They appear to have been newly broken in and are still in very good condition.  They're probably not good for much else besides walking in.
%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(150);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",0);
}



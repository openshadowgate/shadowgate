#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silver ring");
	set_id(({ "ring", "silver ring" }));
	set_short("%^BOLD%^%^WHITE%^silver ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This ring is nothing more than a simple band of silver that is thin but wide.  It looks to have seen much wear but is clearly well-cared-for.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",0);
}



#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hat");
	set_id(({ "hat" }));
	set_short("%^RESET%^%^BOLD%^%^MAGENTA%^a bright pink pointy hat%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^MAGENTA%^a bright pink pointy hat%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^MAGENTA%^This is a bright pink, pointed hat.  It is about two feet tall at the pointy end.  It is made from good quality felt.  If it weren't costume clothing, it looks like something a storybook princess would wear.
%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",4);
}




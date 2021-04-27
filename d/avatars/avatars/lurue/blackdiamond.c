#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("black diamond");
	set_id(({ "diamond", "black diamond", "gem" }));
	set_short("%^BOLD%^%^BLACK%^a black diamond%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a black diamond%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLACK%^One of the rarest types of diamonds, this large black one is about the size of a newborn's fist and is clearly worth a very large chunk of money.  Unpolished except for one small area that has been shorn away to make a flat base, the gem is amazing, not only for its value but the clarity of the gem.%^RESET%^


AVATAR
	);
	set_weight(10);
	set_value(50000);
}

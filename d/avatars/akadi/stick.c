#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^A smooth branch%^RESET%^");
	set_id(({ "stick", "wood", "branch", "twig" }));
	set_short("%^RESET%^%^ORANGE%^A smooth branch%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A smooth branch%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a simple branch, fallen from a tree. It is smooth and slender. A few %^GREEN%^leaves%^ORANGE%^ poke out here and there.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
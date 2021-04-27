#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("talon");
	set_id(({ "talon" }));
	set_short("%^BOLD%^%^WHITE%^A massive %^RED%^talon%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A massive %^RED%^talon%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a massive talon of some sort from what must have been a giant %^BLUE%^beast%^WHITE%^. Deep grooves run along the sides with old dry %^RESET%^%^RED%^blood%^BOLD%^%^WHITE%^ remaining within them. Over all the talon is about 5 feet long and %^BLACK%^razor%^WHITE%^ sharp.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(0);
}
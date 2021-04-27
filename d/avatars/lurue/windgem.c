#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLUE%^blue gem%^RESET%^");
	set_id(({ "gem", "blue gem" }));
	set_short("%^BOLD%^%^BLUE%^a blue gem%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a blue gem%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This blue gem is strangely transparent and glows with a ever churning inner light!%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(0);
}
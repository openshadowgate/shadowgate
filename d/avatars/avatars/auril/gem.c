#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("gem");
	set_id(({ "gem" }));
	set_short("%^BOLD%^%^RED%^A glowing red gem%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A glowing red gem%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This gem is pulsing.

AVATAR
	);
	set_weight(5);
	set_value(0);
}
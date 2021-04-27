#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("iron ingot");
	set_id(({ "ingot", "iron", "block of iron", "iron block" }));
	set_short("%^RESET%^%^CYAN%^A perfect block of iron%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A perfect block of iron%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This huge block is a flawless piece of prepared iron.  Almost the size of a house, it is perfectly square and shows no signs of imperfection.  Strangely it appears to %^RED%^glow%^CYAN%^ softly as though a %^RED%^powerful energy%^CYAN%^ fills it.  Someone working with this would be able to create very powerful items.%^RESET%^

AVATAR
	);
	set_weight(300);
	set_value(0);
}
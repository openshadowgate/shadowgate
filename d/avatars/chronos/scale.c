#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("blue scale");
	set_id(({ "scale" }));
	set_short("%^BOLD%^%^CYAN%^A %^BLUE%^blue%^WHITE%^ dragon%^CYAN%^ scale%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A %^BLUE%^blue%^WHITE%^ dragon%^CYAN%^ scale%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is a scale from a blue dragon, static %^YELLOW%^electricity%^BLUE%^ jumps off of it making your hair stand on end as you hold it. It is about a foot across in each direction and as hard as %^WHITE%^diamond.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(0);
}
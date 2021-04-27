#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("void key");
	set_id(({ "void key", "key" }));
	set_short("%^BOLD%^%^BLACK%^a bar of black energy%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a bar of black energy%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This a bar of black energy.  Though you can hold it, doing so makes you shiver as though something is not right.  A swirling vortex appears to rage within the foot long sleeve, shimmering with unearthly quality that sets your head spinning.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
}

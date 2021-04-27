#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^cracked symbol%^RESET%^");
	set_id(({ "symbol", "cracked symbol", "holy symbol" }));
	set_short("%^BLACK%^%^BOLD%^cracked symbol%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^cracked symbol%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^this symbol, engraved with the holy symbol of Akadi, is cracked almost to snapping in half. However it is still very strong. An aura seems to %^RESET%^%^BOLD%^%^WHITE%^pulse %^RESET%^%^BOLD%^%^BLACK%^from it%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
}
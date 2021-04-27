#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("candy key");
	set_id(({ "key", "candy key" }));
	set_short("%^BOLD%^%^CYAN%^a candy key%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^a candy key%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a key made from hard candy.  You'd be surprised how durable it is.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2);
}

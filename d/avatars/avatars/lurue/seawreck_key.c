#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("brass key");
	set_id(({ "brass key", "key" }));
	set_short("%^YELLOW%^a brass key%^RESET%^");
	set_obvious_short("%^YELLOW%^a brass key%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This key is made of brass and designed with three tines at the end and a large clover leaf style grasp.  The whole thing weighs a good amount and is heavy in your hand.  %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
}

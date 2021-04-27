#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("shamrock");
	set_id(({ "shamrock" }));
	set_short("%^BOLD%^%^GREEN%^vivid shamrock%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^vivid shamrock%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This is nothing more than a shamrock, or four-leaf clover.  It is recognized as a symbol of good luck across many cultures in the world.  This particular specimen is still colored a lively green! What good luck! %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}

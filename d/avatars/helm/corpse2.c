#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpse2");
	set_id(({ "corpse", "body" }));
	set_short("%^BOLD%^%^BLACK%^A charred corpse of a humanoid.%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A charred corpse of a humanoid.%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This body is vaguely humanoid in form but appears more as a large charred lump of coal. It might have been an orc once.


AVATAR
	);
	set_weight(70);
	set_value(0);
}
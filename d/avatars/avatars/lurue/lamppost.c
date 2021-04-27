#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("lamp post");
	set_id(({ "lamp post", "post", "lamp" }));
	set_short("%^YELLOW%^A glowing lightpost%^RESET%^");
	set_obvious_short("%^YELLOW%^A glowing lightpost%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^Made of brightly polished %^RESET%^%^ORANGE%^brass%^YELLOW%^, this glowing lightpost is stationed near the entrance to the ballroom and illuminates the way back inside.%^RESET%^

AVATAR
	);
	set_weight(200);
	set_value(0);
}

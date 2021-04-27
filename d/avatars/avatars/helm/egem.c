#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("gem");
	set_id(({ "gem" }));
	set_short("%^YELLOW%^a marvellous gem%^RESET%^");
	set_obvious_short("%^YELLOW%^a marvellous gem%^RESET%^");
	set_long(
@AVATAR
This gem shines with a faint inner light.

AVATAR
	);
	set_weight(0);
	set_value(0);
}
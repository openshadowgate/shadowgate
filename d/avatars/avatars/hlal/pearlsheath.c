#include <std.h>
inherit "/d/common/obj/sheath/sheath_small";

void create(){
	::create();
	set_name("pearl sheath");
	set_id(({ "small sheath", "sheath", "pearl sheath" }));
	set_short("%^BOLD%^%^WHITE%^a small pearled sheath%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a small pearled sheath%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This is a small weapons sheath that is lined by unfinished pearls in varying colors. There are adjustable silk straps that can tie it to your body. 
");
	set_value(500);
}

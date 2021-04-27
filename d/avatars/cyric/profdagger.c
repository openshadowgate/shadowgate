#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("dagger");
	set_id(({ "sword", "longsword" }));
	set_short("test longsword");
	set_obvious_short("test longsword");
	set_long("test longsword long
yes
");
	set_value(1);
}

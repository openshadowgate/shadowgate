#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("fangs");
	set_id(({ "fangs", "fang", "teeth" }));
	set_short("wicked yellow fangs");
	set_obvious_short("wicked yellow fangs");
	set_long(
@AVATAR
wicked yellow fangs

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("piercing");
	set_prof_type("dagger");
	set_size(1);
	set_wc(1,10);
	set_large_wc(1,10);
	set_property("enchantment",0);
}




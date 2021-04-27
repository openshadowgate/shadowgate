#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("cockroach");
	set_id(({ "insect", "cockroach" }));
	set_short("%^RESET%^%^ORANGE%^A dead cockroach%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A dead cockroach%^RESET%^");
	set_long(
@AVATAR
This is the carapace of a cockroach. It's a large, dark-brown insect with long antennae and a flat body. Six scaly legs protude from the thorax aswell as two pairs of small wings.

AVATAR
	);
	set_weight(0);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("blackrose");
	set_id(({ "rose", "flower", "black rose", "black flower" }));
	set_short("%^BOLD%^%^A Black Rose%^RESET%^");
	set_obvious_short("%^BOLD%^%^A Black Rose%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^This is a beautiful black rose.  The petals are soft and silky and are the shade of the darkest night without moon or starlight.  The rose smells aromatic and its perfume is intoxicating. The stem is unusual for a rose in that it has little next to no thorns.  Both the stem and its leaves are also as black as the flower itself.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}
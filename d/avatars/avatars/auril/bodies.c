#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("body");
	set_id(({ "body", " bodies", " corpse" }));
	set_short("A body covered with blood and ripped apart");
	set_obvious_short("A body covered with blood and ripped apart");
	set_long(
@AVATAR
This man looked to have been in his mid twenties. His hair was short but mostly removed from his body. His body is almost indistingquishable. Gashes and slashes look overwhelmed in his body. A message is cut into his stomach : "Death to the woodsman half-breed."
.

AVATAR
	);
	set_weight(150);
	set_value(0);
}
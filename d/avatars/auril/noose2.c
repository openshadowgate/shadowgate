#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("noose");
	set_id(({ "bodies", "people", "corpses", "men" }));
	set_short("Four people strung up on trees, all with their necks broken");
	set_obvious_short("Four people strung up on trees, all with their necks broken");
	set_long(
@AVATAR
These look like simple folk, in robes and simple gear. Around each neck is a holy symbol of Mielikki. A cut is across each of the victim's faces.

AVATAR
	);
	set_weight(350);
	set_value(0);
}
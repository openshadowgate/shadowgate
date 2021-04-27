#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wagon");
	set_id(({ "wagon" }));
	set_short("%^RESET%^%^ORANGE%^a large horse drawn wagon%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a large horse drawn wagon%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^ORANGE%^This is a large horse drawn wagon.  It has four thick walls to keep whatever it is hauling safe and secure.  Four large spoked wheels provide a sturdy means of transport and you notice that a fifth wheel is secured under the belly to provide a quick repair should one of the first four break.  At the front a wide, flat seat provides a spot for the driver to sit and guide the horses that pull the wagon.%^RESET%^


AVATAR
	);
	set_weight(200);
	set_value(500);
}
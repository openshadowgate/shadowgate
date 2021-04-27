#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("copper bar");
	set_id(({ "bar of copper", "copper bar", "bar" }));
	set_short("%^RESET%^%^ORANGE%^a bar of pure copper%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This bar is about a foot long and half as tall, it is made of pure copper and would be very valuable.  Heavy, you wouldn't be able to carry very many of these without strain.   Stamped into the surface of this bar is one of the many regional sigils found about the realm, signifying from where this bar of copper came.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(3000);
}

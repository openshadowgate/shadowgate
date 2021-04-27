#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("gold bar");
	set_id(({ "bar of gold", "gold bar", "bar" }));
	set_short("%^YELLOW%^a bar of pure gold%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This bar is about a foot long and half as tall, it is made of pure gold and would be very valuable.  Heavy, you wouldn't be able to carry very many of these without strain.   Stamped into the surface of this bar is one of the many regional sigils found about the realm, signifying from where this bar of gold came.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(10000);
}

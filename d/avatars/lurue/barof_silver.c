#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("silver bar");
	set_id(({ "bar of silver", "silver bar", "bar" }));
	set_short("%^BOLD%^%^WHITE%^a bar of pure silver%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This bar is about a foot long and half as tall, it is made of pure silver and would be very valuable.  Heavy, you wouldn't be able to carry very many of these without strain.   Stamped into the surface of this bar is one of the many regional sigils found about the realm, signifying from where this bar of silver came.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(6000);
}

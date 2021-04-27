#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("key");
	set_id(({ "key" }));
	set_short("%^BOLD%^%^RED%^rusty key");
	set_obvious_short("%^BOLD%^%^RED%^rusty key");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A rusty key, I wonder what it goes too?

AVATAR
	);
	set_weight(1);
	set_value(0);
}
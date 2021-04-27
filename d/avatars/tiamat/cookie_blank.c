#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a cookie");
	set_id(({ "cookie", "blank" }));
	set_short("a cookie");
	set_obvious_short("a cookie");
	set_long(
@AVATAR
This is a cookie.  It is left blank for altering later.  Still, might be good for snacking.

AVATAR
	);
	set_weight(1);
	set_value(1);
}
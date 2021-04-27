#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("root");
	set_id(({ "root" }));
	set_short("A sprig of root");
	set_obvious_short("A sprig of root");
	set_long(
@AVATAR
This root has a distinctive %^BOLD%^%^RED%^red %^RESET%^tip.

AVATAR
	);
	set_weight(1);
	set_value(100);
}
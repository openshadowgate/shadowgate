#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("vial");
	set_id(({ "vial" }));
	set_short("%^BOLD%^%^WHITE%^A %^RESET%^%^ORANGE%^corked %^BOLD%^%^WHITE%^vial%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^RESET%^%^ORANGE%^corked %^BOLD%^%^WHITE%^vial%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Inside this vial is a thick milky substance. It swirls about slowly when shaken.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
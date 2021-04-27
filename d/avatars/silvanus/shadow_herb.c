#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Shadow Herb");
	set_id(({ "herb", "shadow herb", "herb of shadow" }));
	set_short("%^BOLD%^%^BLACK%^Shadow Herb%^RESET%^");
	set_obvious_short("shadowy herb");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^You can't tell if this root is real or a part of the shadows from where it came.  It looks to be about 2 foot long, with several smaller roots potruding from it.  Obviously some magic was involved with it's growth.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
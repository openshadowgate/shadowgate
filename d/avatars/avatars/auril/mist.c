#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("mist");
	set_id(({ "mist" }));
	set_short("%^BOLD%^%^BLACK%^A swirling black mist hovers over the corpse%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A swirling black mist hovers over the corpse%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A swirling black mist hovers over the corpse%^RESET%^.

AVATAR
	);
	set_weight(5000);
	set_value(0);
}
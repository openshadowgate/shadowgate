#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tool set");
	set_id(({ "tool set", "set", "tools" }));
	set_short("A small tool set");
	set_obvious_short("A small tool set");
	set_long(
@AVATAR
Contained within this leather pouch is a set of tools most likely used for weaponsmithing.  Inside you see an %^BOLD%^%^BLACK%^oil%^RESET%^%^ORANGE%^cloth%^RESET%^, a %^BOLD%^%^WHITE%^whetstone%^RESET%^, a %^BOLD%^%^RED%^heavy %^RESET%^%^CYAN%^stone%^RESET%^, some spare %^RESET%^%^ORANGE%^leather%^RESET%^, plus a myraid of other files, polishes, such that one would expect to need on day to day weapon repairs.

AVATAR
	);
	set_weight(1);
	set_value(50);
	set_property("lore difficulty",0);
}
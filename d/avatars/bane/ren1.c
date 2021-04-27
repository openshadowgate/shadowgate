#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^A small starburst disk%^RESET%^");
	set_id(({ "disk", "Disk" }));
	set_short("%^BOLD%^%^WHITE%^A small starburst disk%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A small starburst disk%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a small disk about an inch think in the form of a starburst that is near six inches across. Each point has a small sapphire gem inset in it.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
o

AVATAR
	);
	set_property("lore difficulty",1000);
}
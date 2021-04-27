#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("icetear");
	set_id(({ "tear", " icecube", " ice tear" }));
	set_short("%^BOLD%^%^CYAN%^A frozen tear%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A frozen tear%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^A frozen tear from none other than the Ice Queen herself.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^A frozen tear from none other than the Ice Queen herself.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
}
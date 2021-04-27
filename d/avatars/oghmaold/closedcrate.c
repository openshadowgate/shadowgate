#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wooden crate");
	set_id(({ "crate", "wooden crate" }));
	set_short("%^RESET%^%^ORANGE%^A wooden crate%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A wooden crate%^RESET%^");
	set_long(
@AVATAR
This is a 4 foot cubical crate used to ship goods.  The lid has been securely nailed down as to prevent any tampering or such.

AVATAR
	);
	set_weight(25);
	set_value(2000);
	set_property("lore difficulty",0);
}
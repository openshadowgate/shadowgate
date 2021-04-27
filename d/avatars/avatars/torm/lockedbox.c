#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("box");
	set_id(({ "box", "locked box" }));
	set_short("%^RESET%^%^ORANGE%^A small wooden box%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a small wooden box.  There are no hinges visible from the outside of the box, and it is hard to tell the box from the lid.  At the front of the box there is a large %^RESET%^titanium lock plate%^ORANGE%^ with a %^BOLD%^%^BLACK%^small keyhole%^RESET%^%^ORANGE%^ at the centre.  There are %^BOLD%^%^RED%^magical wards%^RESET%^%^ORANGE%^ and %^YELLOW%^sigils%^RESET%^%^ORANGE%^ covering the box.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(25);
	set_lore(
@AVATAR
This was once a very plain wooden box, but it has been covered with magical enchantments to ensure that its contents stay safe and secure.  This sort of box is often used by magi to transport dangerous or valuable items or components.

AVATAR
	);
	set_property("lore difficulty",0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("vial");
	set_id(({ "vial", "blood" }));
	set_short("A small vial of %^RED%^blood%^RESET%^");
	set_obvious_short("A small vial of %^RED%^blood%^RESET%^");
	set_long(
@AVATAR
This is a small vial of blood.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}
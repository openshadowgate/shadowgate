#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("towels");
	set_id(({ "towel" }));
	set_short("Towel");
	set_obvious_short("Towel");
	set_long(
@AVATAR
This is a white terry cloth towel. It's fairly large and could wrap around a normal sized body easily. It's very soft and bright white. It smells of bleach.

AVATAR
	);
	set("read",
@AVATAR
The towel reads "Mask and Istishia, forever in love."

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This towel was a wedding present from Selune to Mask and Istishia on the eve of their wedding.

AVATAR
	);
	set_property("lore difficulty",0);
}
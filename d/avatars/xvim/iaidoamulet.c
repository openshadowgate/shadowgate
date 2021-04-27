#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Amulet of the lion");
	set_id(({ "amulet" }));
	set_short("%^WHITE%^Amulet of the %^YELLOW%^Lion");
	set_obvious_short("small amulet");
	set_long(
@AVATAR
%^WHITE%^This fine amulet is made out of what seems to be ebony, it portrays a Lions head. The face of the lion has two yellow gems as eyes, wich glows brighter when you wear the amulet.

AVATAR
	);
	set_weight(5);
	set_value(500);
}
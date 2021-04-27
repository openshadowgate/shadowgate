#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("sketch");
	set_id(({ "sketch", "drawing", "picture" }));
	set_short("A sketch");
	set_obvious_short("A sketch");
	set_long(
@AVATAR
This is a fine drawing of a half-elven man.  He is sitting in this picture so you cannot tell his height.  His skin is shown as dark and weatherworn.  He has long hair, black as a raven in this picture.  He has almond shaped eyes which are beryl in this drawing.  He shows no trace of body fat whatsoever and looks very fit.  He wears a robe and many sheaths on his person.  But no piece of equipment stands out in particular.

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
}
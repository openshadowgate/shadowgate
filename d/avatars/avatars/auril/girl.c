#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("girl");
	set_id(({ "body" }));
	set_short("A small child's body");
	set_obvious_short("A small child's body");
	set_long(
@AVATAR
The body looks to be of a young girl, cut across the throat and her some of her organs missing.

AVATAR
	);
	set_weight(35);
	set_value(0);
}
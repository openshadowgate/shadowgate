#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wand");
	set_id(({ "wand" }));
	set_short("A long thin wand");
	set_obvious_short("A long thin wand");
	set_long(
@AVATAR
This is a long thin, twisted wand.

AVATAR
	);
	set_weight(1);
	set_value(10);
}
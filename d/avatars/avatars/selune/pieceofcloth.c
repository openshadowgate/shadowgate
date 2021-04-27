#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("cloth");
	set_id(({ "cloth", "piece of cloth", "piece of robe" }));
	set_short("Piece of cloth");
	set_obvious_short("Piece of cloth");
	set_long(
@AVATAR
This is a piece of white cloth. It looks like the part of a robe.

AVATAR
	);
	set_weight(go to lukas);
	set_value(0);
	set_property("lore difficulty",0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("hand");
	set_id(({ "hand", " drow hand", " severed hand" }));
	set_short("Severed Hand");
	set_obvious_short("severed hand");
	set_long(
@AVATAR
This is a severed hand, cleanly cut just above the wrist.  The dark skin indicates it either comes from a dark human or drow, but the long slender fingers suggest the latter.  The severed portion is covered with dried blood, and the hand itself is beginning to give off a rather unpleasant stench.

AVATAR
	);
	set("read",
@AVATAR
You can't read that!

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
Its a hand cut from a drow, that's about it.

AVATAR
	);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("note");
	set_id(({ "note" }));
	set_short("A hand written note");
	set_obvious_short("A hand written note");
	set_long(
@AVATAR
This is a note that has been written on a piece of plain parchment.  You should read it.

AVATAR
	);
	set("read",
@AVATAR
Mithlior,

Do not fail me, you must return my weapon, and you must return the head of the olaf.  

Me expects you by next snow,

Mooraged

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
}
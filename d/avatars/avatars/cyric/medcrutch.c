#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("crutch");
	set_id(({ "crutch", " crude crutch", " wooden crutch" }));
	set_short("Wooden Crutch");
	set_obvious_short("wood crutch");
	set_long(
@AVATAR
this crutch is made of a heavy wood, carved rather crudely and shaped by hand.  The carving is sloppy, and obviously not the work of a master.  It is about right for a person of medium height, but doesn't lookd strong enough to be of any use to a larger than human-sized creature.

AVATAR
	);
	set("read",
@AVATAR
There's nothing on it to read.

AVATAR
	);
     set("langage","str");	set_weight(4);
	set_value(1);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(2);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",0);
}



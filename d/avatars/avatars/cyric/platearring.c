#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("platinum earring");
	set_id(({ "earring", " platinum earring" }));
	set_short("platinum earring");
	set_obvious_short("platinum earring");
	set_long(
@AVATAR
This is an intricate and delicate platinum earring.  It is probably worth a good sum of gold.

AVATAR
	);
	set("read",
@AVATAR
There's nothing on it to read.

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(700);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
}



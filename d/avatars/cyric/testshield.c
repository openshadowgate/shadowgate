#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shield");
	set_id(({ "shield", "testshield" }));
	set_short("Testshield");
	set_long(
@AVATAR
This is me testing item to create a shield

AVATAR
	);
	set("read",
@AVATAR
There's nothing on it to read.

AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(1);
	set_type("armor");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}



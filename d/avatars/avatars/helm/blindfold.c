#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("blindfold");
	set_id(({ "blindfold", "fold" }));
	set_short("A simple blindfold");
	set_obvious_short("A simple blindfold");
	set_long(
@AVATAR
A simple blindfold

AVATAR
	);
	set("read",
@AVATAR
*

AVATAR
	);
     set("langage","elven");	set_weight(0);
	set_value(0);
	set_property("lore difficulty",);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}



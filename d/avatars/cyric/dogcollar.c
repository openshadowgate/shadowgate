#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("collar");
	set_id(({ "collar", "dog collar" }));
	set_short("Dog Collar");
	set_long(
@AVATAR
This is a simple leather strap which is used to identify a pet.

AVATAR
	);
	set("read",
@AVATAR
%^ORANGE%^Ambrosius%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(1);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",0);
}



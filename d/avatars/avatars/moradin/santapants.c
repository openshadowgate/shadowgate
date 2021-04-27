#include <std.h>
inherit "/d/common/obj/clothing/breeches";

void create(){
	::create();
	set_name("santapants");
	set_id(({ "trousers", "pants" }));
	set_short("%^BOLD%^%^WHITE%^White%^BOLD%^%^RED%^-cuffed red trousers%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^White%^BOLD%^%^RED%^-cuffed red trousers%^RESET%^");
	set_long("This is a pair of bright red trousers with the cuffs is trimmed with white rabbit fur.
");
	set_value(5000);
	set_size(2);
	set_property("enchantment",4);
}




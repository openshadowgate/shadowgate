#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("santabelt");
	set_id(({ "belt" }));
	set_short("%^BOLD%^%^BLACK%^Black leather belt with a large %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^%^WHITE%^buckle%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Black leather belt with a large %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^%^WHITE%^buckle%^RESET%^");
	set_long("This is a wide black pollished leather belt with a silver buckle.
");
	set_value(0);
	set_size(2);
	set_property("enchantment",3);
}




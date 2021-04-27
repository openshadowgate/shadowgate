#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("santacoat");
	set_id(({ "coat", "robe" }));
	set_short("%^BOLD%^%^RED%^Red %^BOLD%^%^WHITE%^coat%^BOLD%^%^RED%^ with a %^BOLD%^%^WHITE%^white%^BOLD%^%^RED%^ collar and cuffs%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Red %^BOLD%^%^WHITE%^coat%^BOLD%^%^RED%^ with a %^BOLD%^%^WHITE%^white%^BOLD%^%^RED%^ collar and cuffs%^RESET%^");
	set_long("This is a large warm and plush winter coat in bright red. The cuffs is of white rabbit and looks soft and warm. The long coat goes to the wearers boots.
");
	set_value(20000);
	set_size(2);
	set_property("enchantment",5);
}




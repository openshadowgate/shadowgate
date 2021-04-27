#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("thickly layered scarf");
	set_id(({ "scarf", "thickly layered scarf", " layered scarf" }));
	set_short("%^BOLD%^%^BLACK%^A thickly %^WHITE%^%^CYAN%^l%^BLACK%^a%^RESET%^%^GREEN%^y%^BOLD%^%^BLACK%^e%^CYAN%^r%^BLACK%^e%^GREEN%^d %^BLACK%^scarf%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A thickly %^WHITE%^%^CYAN%^l%^BLACK%^a%^RESET%^%^GREEN%^y%^BOLD%^%^BLACK%^e%^CYAN%^r%^BLACK%^e%^GREEN%^d %^BLACK%^scarf%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^On the %^RESET%^%^ORANGE%^warm %^GREEN%^springs %^BOLD%^%^BLACK%^and %^YELLOW%^summers %^BLACK%^the thick nature of the scarf allows it to be worn loosely around the neck and shoulder"
	"s while retaining its shape, and during the %^CYAN%^colder %^RESET%^%^GREEN%^a%^ORANGE%^u%^GREEN%^t%^RED%^u%^GREEN%^m%^ORANGE%^n %^BOLD%^%^BLACK%^and %^WHITE%^winter %^BLACK%^it can be wrapped tighter"
	" to allow it its true function of keeping its wearer %^RED%^warm%^BLACK%^. Multiple layers of %^WHITE%^s%^RED%^i%^CYAN%^l%^MAGENTA%^k%^GREEN%^s %^BLACK%^have been wrapped and sewn to the thick, warm w"
	"ool cloth, obscuring the dull bl%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^ck shade mostly but allowing it to contrast the brighter silk colors where it is visible. Each length of silk that is wound around t"
	"he scarf holds its own color and has been sewn and formed in its own distinct way.%^RESET%^
"	);
	set_value(9000);
	set_item_bonus("magic resistance",2);
	set_size(2);
	set_property("enchantment",5);
}




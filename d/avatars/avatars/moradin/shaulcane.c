#include <std.h>
inherit "/d/common/obj/weapon/mstaff";

void create(){
	::create();
	set_name("blackcane");
	set_id(({ "cane" }));
	set_short("%^RESET%^%^CYAN%^Elegant %^BOLD%^%^WHITE%^s%^BLACK%^i%^WHITE%^l%^BLACK%^v%^WHITE%^e%^BLACK%^r %^RESET%^%^WHITE%^knobbed %^BOLD%^%^BLACK%^black %^WHITE%^cane%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^Elegant %^BOLD%^%^WHITE%^s%^BLACK%^i%^WHITE%^l%^BLACK%^v%^WHITE%^e%^BLACK%^r %^RESET%^%^WHITE%^knobbed %^BOLD%^%^BLACK%^black %^WHITE%^cane%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a long and slender cane made of the finest ebony. The smooth polished wood stands in perfect contrast to the %^BOLD%^%^WHITE%^s%^BLACK%^i%^WHITE%^l%^BLACK%^v%^WHITE%^e%^BLACK%"
	"^r knob of the cane, and the pointed silvery tip. This is a gentlemans cane of the highest quality.%^RESET%^
"	);
	set_value(100);
	set_property("enchantment",0);
}




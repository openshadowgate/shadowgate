#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
	::create();
	set_name("fine silk robes");
	set_id(({ "robes", "silk", "silk robes", "robe", "fine robes", "fine silk robes" }));
	set_short("%^BOLD%^%^BLUE%^fine %^MAGENTA%^s%^CYAN%^i%^MAGENTA%^lk %^RESET%^%^MAGENTA%^r%^GREEN%^o%^MAGENTA%^b%^GREEN%^e%^MAGENTA%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^fine %^MAGENTA%^s%^CYAN%^i%^MAGENTA%^lk %^RESET%^%^MAGENTA%^r%^GREEN%^o%^MAGENTA%^b%^GREEN%^e%^MAGENTA%^s%^RESET%^");
	set_long("%^GREEN%^This set of robes are of a very fine silk fabric. The robe itself is made to wrap about ones body to allow free movement but clings to it as well. There are two outer pockets, lined with thic"
	"kened silk as well.%^RESET%^
"
	);
	set_value(1000);
	set_size(2);
	set_property("enchantment",1);
}




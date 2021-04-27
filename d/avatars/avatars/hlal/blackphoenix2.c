#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("phoenix pendant");
	set_id(({ "black phoenix pendant", "pendant", "necklace", "phoenix necklace", "black pendant" }));
	set_short("%^BOLD%^%^BLACK%^black ph%^ORANGE%^o%^RESET%^%^RED%^e%^BOLD%^n%^BLACK%^ix pendant%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black ph%^ORANGE%^o%^RESET%^%^RED%^e%^BOLD%^n%^BLACK%^ix pendant%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Hanging from a chain of %^RESET%^%^MAGENTA%^r%^RED%^o%^MAGENTA%^s%^BOLD%^e %^RESET%^%^MAGENTA%^g%^RED%^o%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^d %^BOLD%^%^BLACK%^is this beautifully "
	"detailed ph%^RESET%^%^RED%^o%^YELLOW%^e%^RED%^n%^BLACK%^ix. It is cut from a dark gem of some kind. A %^RESET%^%^RED%^fi%^YELLOW%^e%^RESET%^%^RED%^ry l%^YELLOW%^i%^RESET%^%^RED%^ght %^BOLD%^%^BLACK%^p"
	"ulses beneath its dark breast. It it meant to symbolize hope in the darkest hour.%^RESET%^
"	);
	set_value(500);
	set_size(2);
	set_property("enchantment",0);
}




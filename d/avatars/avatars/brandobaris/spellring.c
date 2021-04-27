#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("silver ring");
	set_id(({ "ring", "cheap ring", "silver ring", "cheap silver ring" }));
	set_short("%^RESET%^a c%^BOLD%^h%^BLACK%^e%^WHITE%^a%^RESET%^p s%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^v%^WHITE%^e%^RESET%^r r%^BOLD%^i%^RESET%^ng");
	set_obvious_short("%^RESET%^a c%^BOLD%^h%^BLACK%^e%^WHITE%^a%^RESET%^p s%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^v%^WHITE%^e%^RESET%^r r%^BOLD%^i%^RESET%^ng");
	set_long("This unimpressive ring looks to be made from low-quality %^BOLD%^silver%^RESET%^, and is blemished by numerous s%^BOLD%^%^BLACK%^c%^WHITE%^r%^RESET%^at%^BOLD%^c%^RESET%^hes and i%^BOLD%^m%^RESET%^p%^B"
	"OLD%^%^BLACK%^e%^WHITE%^r%^RESET%^f%^ORANGE%^e%^WHITE%^ct%^BOLD%^i%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^s.
"	);
	set_value(0);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^You slip the unassuming ring onto your finger, and a thought crosses your mind: could you perhaps %^RED%^<%^ORANGE%^use%^RED%^> %^WHITE%^this on something?%^RESET%^");
	return 1;
}



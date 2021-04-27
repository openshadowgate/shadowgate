#include <std.h>
inherit "/d/common/obj/armour/breastplate";

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^D%^YELLOW%^w%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^v%^YELLOW%^e%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^B%^RESET%^r%^BOLD%^%^WHITE%^e%^RESET%^a%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^p%^RESET%^l%^BOLD%^%^WHITE%^a%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^");
	set_id(({ "breastplate", "plate", "armor" }));
	set_short("%^RESET%^%^ORANGE%^D%^YELLOW%^w%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^v%^YELLOW%^e%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^B%^RESET%^r%^BOLD%^%^WHITE%^e%^RESET%^a%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^p%^RESET%^l%^BOLD%^%^WHITE%^a%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^D%^YELLOW%^w%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^v%^YELLOW%^e%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^B%^RESET%^r%^BOLD%^%^WHITE%^e%^RESET%^a%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^p%^RESET%^l%^BOLD%^%^WHITE%^a%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is a breastplate made of %^RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^e%^BOLD%^e%^RESET%^%^CYAN%^l%^ORANGE%^ by a dwarven smith. It has a front and black plate that protects the"
	" torso, with sturdy buckles on the sides to keep it in place. The armor allows free movement, although the lack of protection to the exposed legs and lower back (kidneys!) is some cause for concern. T"
	"he armor is %^BOLD%^%^WHITE%^e%^RESET%^m%^BOLD%^%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^s%^RESET%^s%^BOLD%^%^WHITE%^e%^RESET%^d%^ORANGE%^ with a beautiful design of a %^RED%^hammer%^RESET%^ made of %^CYA"
	"N%^silver%^RESET%^%^ORANGE%^. Overall it is both a very finely made piece of art and a highly functional set of armor.%^RESET%^
"
	);
	set_value(5000);
	set_size(2);
	set_property("enchantment",1);
}




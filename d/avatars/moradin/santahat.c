#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("santahat");
	set_id(({ "hat" }));
	set_short("%^BOLD%^%^WHITE%^White trimmed %^BOLD%^%^RED%^red hat with a long %^BOLD%^%^WHITE%^white %^BOLD%^%^RED%^tassle%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^White trimmed %^BOLD%^%^RED%^red hat with a long %^BOLD%^%^WHITE%^white %^BOLD%^%^RED%^tassle%^RESET%^");
	set_long("This warm and plush hat is bright red and the cuffs is trimmed with white rabbit fur. The pointy and soft hat have a long tassle topped with white rabbit fur.
");
	set_value(0);
	set_size(2);
	set_property("enchantment",4);
}




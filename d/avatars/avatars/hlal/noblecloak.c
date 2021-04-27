#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("%^RED%^nobleman's cloak%^RESET%^");
	set_id(({ "cloak", "cape", "wrap", "nobleman's cloak", "red cloak" }));
	set_short("%^RED%^finely made nobleman's cloak%^RESET%^");
	set_obvious_short("%^RED%^red sp%^BOLD%^i%^RESET%^%^RED%^dersilk cloak%^RESET%^");
	set_long("%^BOLD%^%^RED%^Tailored of the finest spidersilk available, the cloak is designed to catch the eye. The stitching itself is a work of art, fine lines of scrollwork lining the edges of the piece. The i"
	"nside of the cloak is lined with a warmer removeable cloth to allow its use in any season.%^RESET%^
"	);
	set_value(12000);
	set_lore("%^BOLD%^%^WHITE%^At first glance there is nothing about the cloak that stands out. Noble men and women from all over the world are known to prize the costly and hard to get spidersilk. This one in par"
	"ticular bears the signature of Aartumis Fengold, who is known for tailoring for only the most popular of nobles. His work was highly sought after as he often enchanted his work with special properties"
	".%^RESET%^
"	);
	set_property("lore difficulty",7);
	set_item_bonus("charisma",1);
	set_item_bonus("influence",2);
	set_size(2);
	set_property("enchantment",3);
}




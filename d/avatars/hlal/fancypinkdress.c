#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("fancy pink dress");
	set_id(({ "fancy pink dress", "pink dress", "dress", "fancy dress" }));
	set_short("%^RESET%^%^MAGENTA%^f%^WHITE%^a%^MAGENTA%^ncy p%^WHITE%^i%^MAGENTA%^nk d%^WHITE%^r%^MAGENTA%^ess%^RESET%^");
	set_long("%^BOLD%^%^MAGENTA%^What little girl wouldn't love one of these beautiful creations. Every inch of the dress is a sight to behold from the bold pink velvet that lines the outer dress to the frilly whit"
	"e lace that is layered beneath to give the dress just enough poof. There are custom patterns sewn into the seams which only a master of this technique could manage.%^RESET%^
"	);
	set_value(20000);
	set_lore("%^BOLD%^%^WHITE%^The dress is one of the more fashionable for children of both nobility and rich merchants. While the style is common enough it is very rarely seen as only a master of the craft would "
	"dare spend so much on the best cloth in the realms.
"	);
	set_property("lore difficulty",1);
	set_item_bonus("influence",3);
	set_item_bonus("damage resistance",5);
	set_size(2);
	set_property("enchantment",3);
}




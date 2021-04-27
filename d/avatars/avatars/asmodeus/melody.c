#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("melody of a thousand notes");
	set_id(({ "flute" }));
	set_short("%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^e%^%^BOLD%^%^GREEN%^l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^dy%^%^RESET%^ %^BOLD%^%^GREEN%^o%^RESET%^%^WHITE%^f%^RESET%^ %^GREEN%^a%^RESET%^ %^BOLD%^%^GREEN%^th%^BOLD%^%^GREEN%^ou%^RESET%^%^BOLD%^%^BLACK%^sa%^RESET%^%^BOLD%^%^GREEN%^nd no%^RESET%^%^GREEN%^t%^RESET%^%^WHITE%^e%^BOLD%^%^GREEN%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^jagged jade flute%^RESET%^");
	set_long("%^BOLD%^%^GREEN%^Formed from a single piece of raw jade that has been carved into a tube, this flute is an amazing piece of craftsmanship. As the light travels through the flute, it reflects and refra"
	"cts the light into a thousand shards. The mouthpiece has been carved and smoothed, and each finger hole is meticulously carved. The flute extends farther then it should however, and a thin strip of si"
	"lk has been tied to the end, as if you could hold it. All along the length of the flute are%^RESET%^ %^BOLD%^%^BLACK%^engravings %^RESET%^%^BOLD%^%^GREEN%^and %^BOLD%^%^GREEN%^pictographs.%^RESET%^
"	);
	set_value(500);
	set_lore("%^BOLD%^%^WHITE%^The melody of a thousand notes was crafted by an elven artificer a thousand years ago. It is said that an avatar of Oghma inhabited the elfs body during its creation, filling the elfs"
	" head with every song known to the planes. The artifact moved from bard to bard, and any who held it seemed to become the most renowned and famous, always creating masterpieces. The flute fell into ob"
	"scurity when it fell into the hands of a young man during a competition in the city of Asgard. To everyones shock the man lost the competition to another bard with a mundane harp. He swore he would fi"
	"nd the most complete and perfect music and disappeared.%^RESET%^
"	);
	set_property("lore difficulty",30);
	set_item_bonus("caster level",2);
	set_item_bonus("attack bonus",3);
	set_item_bonus("damage bonus",3);
	set_property("enchantment",5);
}




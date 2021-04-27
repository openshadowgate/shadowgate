#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^C%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^e%^BLUE%^d%^RESET%^%^MAGENTA%^ nipple %^YELLOW%^rings%^RESET%^");
	set_id(({ "chained nipple rings", "chained rings", "nipple", "nipple rings", "rings" }));
	set_short("%^BOLD%^%^WHITE%^C%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^e%^BLUE%^d%^RESET%^%^MAGENTA%^ nipple %^YELLOW%^rings%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^C%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^e%^BLUE%^d%^RESET%^%^MAGENTA%^ %^YELLOW%^rings%^RESET%^");
	set_long("%^RESET%^This is a pair of small %^YELLOW%^rings%^RESET%^ connected together by a slender %^BOLD%^%^WHITE%^c%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^RESET%^. They are designed to be inserted into ones"
	" %^MAGENTA%^nipples%^RESET%^. Only the most %^GREEN%^wickedly%^RESET%^ %^BOLD%^%^MAGENTA%^p%^YELLOW%^e%^MAGENTA%^rv%^YELLOW%^e%^MAGENTA%^r%^YELLOW%^s%^MAGENTA%^e%^RESET%^ would even begin to wear such"
	" a thing.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^RESET%^%^RED%^These rings are believe to have been worn under the garments (or sometimes none at all) of Sune herself! Though, only those who Sune herself deems beautiful enough have ever been able "
	"to glance at them.%^RESET%^
"
	);
    set_property("lore difficulty",10);
    set("chabonus",1);
	set_size(2);
	set_property("enchantment",1);
}




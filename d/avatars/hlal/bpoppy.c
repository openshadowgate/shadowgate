#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("black poppy");
	set_id(({ "poppy", "black poppy" }));
	set_short("%^BOLD%^%^BLACK%^a sm%^RESET%^a%^BOLD%^%^BLACK%^ll b%^RESET%^la%^BOLD%^%^BLACK%^ck p%^RESET%^o%^BOLD%^%^BLACK%^ppy%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a sm%^RESET%^a%^BOLD%^%^BLACK%^ll b%^RESET%^la%^BOLD%^%^BLACK%^ck p%^RESET%^o%^BOLD%^%^BLACK%^ppy%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^For a dark flower, this six petaled flower is very showy. Its petals begin in an unusual crumple at the bud and flatten out towards the edges as they finish blooming. Someone has take"
	"n the time to preserve this one and attach it to an almost unnoticeable hairpin.%^RESET%^
"	);
	set_value(8000);
	set_lore("%^RED%^Floral hair accessories are popular with the ladies in most cases, but the poppy in particular has special meanings in many a culture. A dark one like this one was often used in rituals in the "
	"temple of Loviatar before she was defeated. There are tales a small few who still worship her and are looking for ways to bring her back into power.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("sight bonus",2);
	set_item_bonus("armor bonus",2);
	set_size(2);
	set_property("enchantment",5);
}




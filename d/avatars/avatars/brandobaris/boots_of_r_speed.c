#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("boots of relative speed");
	set_id(({ "boots", "leather boots", "boots of speed", "boots of relative speed" }));
	set_short("%^BOLD%^%^BLACK%^Boots of R%^RESET%^e%^BOLD%^%^BLACK%^l%^WHITE%^at%^BLACK%^i%^RESET%^v%^BOLD%^%^BLACK%^e Sp%^WHITE%^ee%^BLACK%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a pair of %^WHITE%^fine %^BLACK%^leather boots%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^These boots are made of a decent quality leather, and look to be quite expensive, if slightly worn. They seem to weigh only half as much as a pair of boots this size would normally, a"
	"nd a faint %^RED%^m%^BLACK%^i%^RED%^s%^BLACK%^t%^RED%^y a%^BLACK%^u%^RED%^ra %^BLACK%^surrounds them. The dulled finish of the %^RESET%^steel %^BOLD%^%^BLACK%^buckles serves to catch faint reflections"
	" of %^BLUE%^v%^RESET%^%^BLUE%^i%^BOLD%^br%^RESET%^%^BLUE%^a%^BOLD%^t%^RESET%^%^BLUE%^in%^BOLD%^g %^BLACK%^light, as the boots seem to give off faint %^RESET%^%^GREEN%^quivers %^BOLD%^%^BLACK%^from tim"
	"e to time. A faint sense of %^MAGENTA%^power %^BLACK%^seems to emanate from within them.%^RESET%^
"	);
	set_value(5000);
	set_lore("The Boots of Speed are legendary artifacts prized by swordsmen across all the world, lending their wearer a preternatural speed and an inhuman control over their own velocity and orientation. At last,"
	" these artifacts no longer need remain solely in the possession of the most elite of adventurers, for I have discovered a means by which to easily replicate their enchantment. Soon, these boots will b"
	"e as common amongst warriors as your standard longsword, purchasable in any marketplace! Of course, I haven't tested the magic's permanence yet, and the materials used to make the boots were not of th"
	"e highest quality, but...eh, what difference could that make? I'm sure they'll turn out exactly the same.

-Taken from the journal of Master Enchanter Phelius the Half-Hearted.
"	);
	set_property("lore difficulty",15);
	set_item_bonus("damage resistance",2);
	set_item_bonus("athletics",2);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" laces up the boots.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You lace up the boots, feeling slightly %^RESET%^quicker%^BOLD%^%^BLACK%^, but only just.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" unlaces the boots.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull the boots off, feeling slightly %^RESET%^sluggish%^BOLD%^%^BLACK%^, but only just.%^RESET%^");
	return 1;
}


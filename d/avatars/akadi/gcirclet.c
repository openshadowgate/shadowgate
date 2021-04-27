#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^a %^BOLD%^%^RED%^ga%^RESET%^%^RED%^rn%^BOLD%^%^RED%^et%^RESET%^%^RED%^ cir%^BOLD%^c%^RESET%^%^RED%^let%^RESET%^");
	set_id(({ "circlet", "garnet circlet" }));
	set_short("%^BOLD%^%^RED%^Ga%^RESET%^%^RED%^rn%^BOLD%^%^RED%^et%^RESET%^%^RED%^ cir%^BOLD%^c%^RESET%^%^RED%^let%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^a %^BOLD%^%^RED%^ga%^RESET%^%^RED%^rn%^BOLD%^%^RED%^et%^RESET%^%^RED%^ cir%^BOLD%^c%^RESET%^%^RED%^let%^RESET%^");
	set_long(
@AVATAR
%^RESET%^The s%^BOLD%^%^WHITE%^il%^RESET%^v%^BOLD%^%^WHITE%^er%^RESET%^y hematite of this circlet has been treated to a lovely shade of %^RED%^rose%^RESET%^. The metal is thinly cut but is not overly pliable in its circular design. It is designed to fit perfectly, and it is mostly unadorned except for a single, teardrop-shaped %^BOLD%^%^RED%^ga%^BOLD%^%^BLACK%^r%^RED%^net%^RESET%^ that rests against the wearer's forehead, sparkling %^BOLD%^bri%^RESET%^gh%^BOLD%^tly%^RESET%^ when the light hits it. This is an exceptionally well-crafted piece of jewelry, and would make an excellent addition to any lady's collection. The sturdiness of the metal even suggests it might offer a small amount of protection.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^This is an exclusive piece of jewelry thought long lost to the ages. It once belonged to the daughter of a king, passed down from generations of women. It was seemingly stolen by a skilled thief nearly a century ago, and though it was sought after, never found.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",11);
	set_type("chain");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^The garnet %^BOLD%^%^RED%^g%^RESET%^%^RED%^l%^BOLD%^%^RED%^itte%^BOLD%^%^RED%^r%^RESET%^%^RED%^s in the light.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The circlet fits perfectly on your head.%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+" carefully sets aside the headpiece.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You regretfully remove the lovely headpiece.%^RESET%^ ");
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}

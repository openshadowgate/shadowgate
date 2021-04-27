#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("stockings");
	set_id(({ "stockings", "socks", "pants", "striped stockings" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^S%^BLACK%^t%^BLUE%^o%^BLACK%^c%^BLUE%^k%^BLACK%^i%^BLUE%^n%^BLACK%^g%^BLUE%^s of Witch%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLUE%^s%^BLACK%^t%^BLUE%^r%^BLACK%^i%^BLUE%^p%^BLACK%^e%^BLUE%^d stockings%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLUE%^This is a set of soft cotton stockings, decorated in broad stripes of %^BLACK%^black%^BLUE%^ and blue.  The stockings are worn all the way to the upper thigh and would keep the wearer cozy warm.  Although the stockings are cute, on closer inspection you detect a musty smell about them and notice the stitching is rather haphazard.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(700);
	set_lore(
@AVATAR
Legends tell of a most unusual hag that once lived in the Yntala forest.  After killing her parents, the hag took pity on their baby child and raised her as a hag.  The little witch learned all of the hag's dark magic.  The hag doted on the little witch, even stitching her some cute striped stockings.  All was well until the young witch saw her first human other than herself, a young prince that she immediately fell in love with.  Resentful that the hag never let her know of her true heritage, the little witch used the hag's own magic spell to kill her during her slumber.

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^BOLD%^%^BLUE%^slips on their stockings and wiggles their toes.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^You slip on the stockings and wiggle your toes!%^RESET%^");
	ETO->set_property("magic resistance",4);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^BOLD%^%^BLUE%^rolls off their stockings and seem more vulnerable.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^You roll down the stockings and feel less whimsical.%^RESET%^");
	ETO->set_property("magic resistance",-4);
	return 1;
}

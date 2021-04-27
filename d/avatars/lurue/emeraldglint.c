#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "emerald ring", "emerald glint", "glint" }));
	set_short("%^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d G%^WHITE%^l%^RESET%^i%^GREEN%^n%^BOLD%^t%^RESET%^");
	set_obvious_short("%^RESET%^a smooth %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d %^RESET%^ring");
	set_long(
@AVATAR

%^RESET%^%^GREEN%^This strange little ring is very small and would likely only fit on a child's finger.  Even so it is finely made of a solid piece of what looks like %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d%^RESET%^%^GREEN%^.  Only on closer inspection can one tell that it isn't emerald at all but some curious material that holds a myriad of shades from %^YELLOW%^yellow %^RESET%^%^GREEN%^and %^BOLD%^%^BLACK%^black %^RESET%^%^GREEN%^to %^BOLD%^%^BLUE%^blue %^RESET%^%^GREEN%^and even faint hints of %^MAGENTA%^purple%^GREEN%^.  The whole band is made of this material and seems as sturdy and hard as any piece of mithril, clearly a curious item.%^RESET%^


AVATAR
	);
	set_weight(1);
	set_value(15000);
	set_lore(
@AVATAR
Valas, Arch Mage of Mystra, was captured by Klauth when he bravely attempted to drive the giant red dragon away from the Shadow Deserts all alone.  His capture led several brave souls, among them Adderlash of Grumbar, Erieen of Kelemvor, Azalon of Lathander and Snog of Istishia to brave the dangers of Klauth's island in an attempt to free their friend.  The small mercury dragon Zhashabur, friend to Valas and Adderlash, risked his life to draw Klauth away.  Doing so nearly cost him his, but thanks to the efforts of these brave adventurers, not only was Valas saved but Zhashabur was returned from the dead.  In repayment, the little dragon gifted this ring made from a portion of the dragon's claw to Adderlash in thanks. 

AVATAR
	);
	set_property("lore difficulty",18);
	set("strbonus",1);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^The strength of the dragon flows through you!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^You feel weak and mortal once more.%^RESET%^");
	return 1;
}


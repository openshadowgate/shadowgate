#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("earring studs");
	set_id(({ "earrings", "studs", "stud earrings", "crystal earrings", "crystalline earrings" }));
	set_short("%^BOLD%^%^CYAN%^C%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^y%^RESET%^%^BLUE%^s%^BOLD%^t%^RESET%^%^CYAN%^a%^BOLD%^l Memories%^RESET%^");
	set_obvious_short("%^RESET%^pair of %^BOLD%^%^CYAN%^cr%^RESET%^%^CYAN%^ys%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^a%^BOLD%^l%^RESET%^%^CYAN%^li%^BOLD%^ne %^RESET%^stud earrings%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^These earrings are little more then a small %^WHITE%^stud %^CYAN%^with a facetted %^BOLD%^crystal %^RESET%^%^CYAN%^set upon them.  Very small, they would add a tiny bit of %^WHITE%^s%^CYAN%^p%^WHITE%^ar%^BOLD%^%^CYAN%^k%^RESET%^le %^CYAN%^to one's ear and would look comely upon both a man or woman.  A pair, they could be worn one on each ear or both upon one ear as the wearer felt inclined.  The small post is made of pure %^WHITE%^silver %^CYAN%^while the crystals are of a %^BOLD%^%^CYAN%^sh%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^m%^RESET%^%^BLUE%^m%^BOLD%^e%^RESET%^%^CYAN%^ri%^BOLD%^ng %^RESET%^%^CYAN%^blue shade.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
Valas, Arch Mage of Mystra, was captured by Klauth when he bravely attempted to drive the giant red dragon away from the Shadow Deserts all alone.  His capture led several brave souls, among them Adderlash of Grumbar, Erieen of Kelemvor, Azalon of Lathander and Snog of Istishia to brave the dangers of Klauth's island in an attempt to free their friend.  The small mercury dragon Zhashabur, friend to Valas and Adderlash, risked his life to draw Klauth away.  Doing so nearly cost him his, but thanks to the efforts of these brave adventurers, not only was Valas saved but Zhashabur was returned from the dead.  In repayment, the little dragon gifted these earrings, made from a portion of the crystal the mage was once held in, to Valas in thanks. 


AVATAR
	);
	set_property("lore difficulty",18);
	set("wisbonus",1);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^There is a brief sparkle of light as "+ETOQCN+" wears their %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^\.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You set the %^RESET%^"+query_short()+" %^BOLD%^%^CYAN%^into your ears.%^RESET%^");
	return 1;
}



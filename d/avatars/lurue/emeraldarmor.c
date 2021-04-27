#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("full plate");
	set_id(({ "armor", "fullplate", "plate", "full plate", "emerald gleam", "emeralds gleam", "emerald's gleam" }));
	set_short("%^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d's G%^WHITE%^l%^RESET%^e%^GREEN%^a%^BOLD%^m%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^a set of %^BOLD%^%^WHITE%^m%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^r%^BOLD%^%^WHITE%^or b%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^g%^BOLD%^%^WHITE%^ht %^RESET%^%^GREEN%^emerald armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^Gleaming with a bejeweled, %^BOLD%^emerald brightness%^RESET%^%^GREEN%^, the plates of this armor are created from the fused scales of a dragon.  Brilliantly polished, the gem like hue %^BOLD%^%^GREEN%^shimmers%^RESET%^%^GREEN%^ in the light, flickering with %^BOLD%^greens%^RESET%^%^GREEN%^, %^YELLOW%^yellows%^RESET%^%^GREEN%^, %^BOLD%^%^BLACK%^blacks%^RESET%^%^GREEN%^, %^CYAN%^blues %^GREEN%^and a myriad of other shades all of which blend together to create that %^BOLD%^emerald gleam%^RESET%^%^GREEN%^.  The breast and back plates each feature an %^WHITE%^ivory inlay %^GREEN%^of a raised fist holding a pair of scales.  The fist appears to be made of %^WHITE%^bone %^GREEN%^while the scales are crafted from %^WHITE%^%^BOLD%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^ery %^RESET%^%^GREEN%^scales that flash and glimmer like mirrors.  Under the plates, a suit of %^YELLOW%^golden chain %^RESET%^%^GREEN%^protects the wearer, each link has been fashioned into the shape of a finger clutching at the base of the next, hooking around instead of through the links, like a thousand tiny hands reaching upward.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(20000);
	set_lore(
@AVATAR
Valas, Arch Mage of Mystra, was captured by Klauth when he bravely attempted to drive the giant red dragon away from the Shadow Deserts all alone.  His capture led several brave souls, among them Adderlash of Grumbar, Erieen of Kelemvor, Azalon of Lathander and Snog of Istishia to brave the dangers of Klauth's island in an attempt to free their friend.  The small mercury dragon Zhashabur, friend to Valas and Adderlash, risked his life to draw Klauth away.  Doing so nearly cost him his, but thanks to the efforts of these brave adventurers, not only was Valas saved but Zhashabur was returned from the dead.  In repayment, the little dragon gifted this armor to Eireen in thanks. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" dons their suit of armor, a bell like tone sounds from their vicinity.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^YELLOW%^golden links%^WHITE%^ of the chainmail create a soothing bell like tone as you draw on your suit of armor.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" removes their suit of armor, a bell like tone sounds from their vicinity.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^YELLOW%^golden links%^WHITE%^ of the chainmail create a soothing bell like tone as you remove your suit of armor.%^RESET%^");
	return 1;
}


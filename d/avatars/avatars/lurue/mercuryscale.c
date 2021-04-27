#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dragon scale");
	set_id(({ "mercury scale", "dragon scale", "scale" }));
	set_short("%^BOLD%^%^BLACK%^m%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^cu%^RESET%^r%^BOLD%^%^BLACK%^y d%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^go%^RESET%^n %^BOLD%^%^BLACK%^s%^WHITE%^c%^RESET%^a%^BOLD%^%^BLACK%^le%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a m%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^cu%^RESET%^r%^BOLD%^%^BLACK%^y c%^WHITE%^o%^RESET%^l%^BOLD%^%^BLACK%^or%^RESET%^e%^BOLD%^%^BLACK%^d p%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Diamond shaped, this little scale is from a %^BOLD%^%^BLACK%^m%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^cu%^RESET%^r%^BOLD%^%^BLACK%^y "
"d%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^go%^RESET%^n. %^BOLD%^%^BLACK%^It can be worn due to the sharp little thorn that edges backwards and allows it to be hooked "
"onto a garment much like a pin.  Bright as a %^WHITE%^mirror%^BLACK%^ the scale glitters brightly wherever it goes.%^RESET%^");
	set_weight(1);
	set_value(500);
	set_lore("%^BOLD%^%^WHITE%^Given by %^BLACK%^Z%^WHITE%^h%^RESET%^a%^BOLD%^%^BLACK%^sha%^RESET%^b%^BOLD%^%^BLACK%^ur the M%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^cu"
"%^RESET%^r%^BOLD%^%^BLACK%^y D%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^go%^RESET%^n %^BOLD%^%^WHITE%^to those who freed him from his captivity at the hands of "
"%^BOLD%^%^RED%^Klauth the Red Dragon%^BOLD%^%^WHITE%^! Though its but a little scale, such a gift is often a sign of favor or reward and can be used to seek aid in "
"a time of need from the one who handed the gift out.%^RESET%^");
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "left hand","right hand" }));
	set_item_bonus("magic resistance",1);
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^The scale glitters brightly just like a mirror!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^The scale glitters brightly just like a mirror!%^RESET%^");
	return 1;
}


#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bandedmail");
	set_id(({ "ivory banded", "banded mail", "banded", "armor" }));
	set_short("%^BOLD%^%^WHITE%^I%^RESET%^v%^BOLD%^%^WHITE%^ory B%^RESET%^a%^BOLD%^%^WHITE%^nd%^RESET%^e%^BOLD%^%^WHITE%^d M%^RESET%^a%^BOLD%^%^WHITE%^il%^RESET%^");
	set_obvious_short("%^RESET%^a set of pale %^BOLD%^%^WHITE%^b%^RESET%^a%^BOLD%^%^WHITE%^nd%^RESET%^e%^BOLD%^%^WHITE%^d m%^RESET%^a%^BOLD%^%^WHITE%^il%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This mail is made from hundreds of small square plates of ivory backed by thick, padded leather.  The suit looks old as the ivory has %^YELLOW%^yellowed %^WHITE%^and worn, but it still seems functional and quite protective.  Symbols for various elements are carved into the ivory plates using a %^RESET%^silver dye %^BOLD%^%^WHITE%^to make them stand out and cause the armor to flicker in the light.%^RESET%^

AVATAR
	);
	set_weight(40);
	set_value(100);
	set_lore(
@AVATAR
The hunters of Umlur were said to be great and powerful warriors as well as swift hunters.  They specialized in fighting and bringing down large gray beasts with mighty ivory tusks and the ability to crush a man like so many weeds.  From these creatures, the tusks were taken and made into round plates, then etched with symbols that were said to be magical.  From these, armor was created to help protect the warriors in their next battle. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The silver symbols on "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^glitter as "+ETOQCN+" puts their armor on.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You strap on your "+query_short()+" %^BOLD%^%^WHITE%^and feel strong enough to take on the world.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The silver symbols on "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^glitter as "+ETOQCN+" removes their armor.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The silver symbols of the "+query_short()+" %^BOLD%^%^WHITE%^glitter as you remove your armor.%^RESET%^");
	return 1;
}

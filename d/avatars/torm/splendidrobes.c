#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Splendid Robes");
	set_id(({ "robe", "robes", "splendid robes" }));
	set_short("%^BOLD%^%^BLUE%^S%^WHITE%^p%^BLUE%^lendid R%^GREEN%^o%^MAGENTA%^b%^WHITE%^e%^YELLOW%^s%^RESET%^");
	set_obvious_short("%^BLUE%^Splendid Robes%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^These robes are formed of several layers of silk robes worn one on top of another.  The outermost robe is %^BLUE%^a striking cobalt blue d%^WHITE%^e%^BLUE%^corated %^WHITE%^wi%^BLUE%^th a s%^WHITE%^w%^BLUE%^irling p%^WHITE%^atte%^BLUE%^rn of si%^WHITE%^lv%^BLUE%^er embr%^WHITE%^o%^BLUE%^idery%^CYAN%^.  Beneath the outer robe the collars of each of the lower robes are visible.  These are plain silk robes in %^GREEN%^green, %^MAGENTA%^pink, %^WHITE%^white and %^YELLOW%^yellow.%^CYAN%^  The numerous folds of these robes contain a fair sized pocket.


AVATAR
	);
	set_weight(10);
	set_value(2500);
	set_lore(
@AVATAR
%^MAGENTA%^This style of robes is most commonly found in the far south-eastern areas of the Tsarvani Empire.  The various combinations of colours are used there to denote membership of particular schools of magical study, with the number of robes denoting seniority.  The subtleties of the colours and layers have been overlooked by those who have adopted the style within these realms however.

AVATAR
	);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" wraps themselves in layer upon layer of silk%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You carefully %^GREEN%^wear %^MAGENTA%^each %^WHITE%^layer of %^YELLOW%^robes%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" removes several layers of silk robes%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You remove %^BOLD%^%^WHITE%^each%^MAGENTA%^ layer of %^GREEN%^the silk %^BLUE%^robes in turn%^RESET%^");
	return 1;
}

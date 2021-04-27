#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^BLUE%^blue velvet dress%^RESET%^");
	set_id(({ "dress", "sapphire dress", "ladys luck", "lady's luck" }));
	set_short("%^BOLD%^%^BLUE%^L%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^d%^RESET%^%^BLUE%^y%^BOLD%^%^BLUE%^'%^RESET%^%^BLUE%^s %^BOLD%^%^WHITE%^L%^RESET%^u%^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^k%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^blue v%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^lv%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^t dress%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This stunning dress is crafted from %^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^p%^BOLD%^%^BLUE%^ph%^RESET%^%^BLUE%^i%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^ v%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^lv%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^t and is very soft to the touch. It clings nicely to the wearer's torso, but not so tightly that it is constraining. The skirt, which reaches almost to the knees, flares out from the waist and allows ample movement of the legs. %^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^ peeks out from beneath the blue skirt, adding a touch of color to the dress. Small and fashionable %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^BLUE%^ buttons shaped like birds keep the dress fastened tightly.%^RESET%^


AVATAR
	);
	set_weight(10);
	set_value(3000);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^This dress is so exquisitely rare that the holder must indeed be smiled upon by %^BOLD%^%^WHITE%^The L%^RESET%^a%^BOLD%^%^WHITE%^dy of L%^BOLD%^%^BLACK%^uc%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^!%^RESET%^


AVATAR
	);
	set_property("lore difficulty",3);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You hear a playful giggle!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You carefully slip out of the soft dress.%^RESET%^");
	return 1;
}

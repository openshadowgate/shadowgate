#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fishy shirt%^RESET%^");
	set_id(({ "shirt", "fish shirt" }));
	set_short("%^RESET%^%^CYAN%^Fishsk%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^n Shirt%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^shirt of fish skin%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^ This is a thin, flexible shirt made from the skin of a deep sea fish.  It has a pleasant blue-ish color and shining %^BOLD%^%^WHITE%^scales %^RESET%^%^CYAN%^grace the shoulders and collar of the shirt.  It has been creatively sewn together with tough cord of unknown origin.  A few %^BOLD%^%^MAGENTA%^coral %^RESET%^%^CYAN%^buttons will help ensure it fits most people comfortably, as well as keep their upper body watertight.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1899);
	set_lore(
@AVATAR
Shirts, and other clothing items made from this strange fish skin have been witnessed throughout history.  Although the fish species is still unknown, it is suspected that they are farmed by merfolk to provide clothing that is attractive, waterproof and offers some protection.  A shirt of this quality is a fetching prize, and was probably worn by the upper caste of mer-society.

AVATAR
	);
	set_property("lore difficulty",13);
	set("chabonus",1);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" dons an attractive fish scale shirt.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The scales on the shirt glimmer as you don the garment!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" looks sort of dull while removing the fish skin shirt.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You feel less exotic without the shirt on.%^RESET%^");
	return 1;
}

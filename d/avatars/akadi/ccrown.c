#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^C%^RESET%^r%^BOLD%^%^WHITE%^o%^RESET%^w%^BOLD%^%^WHITE%^n of %^BOLD%^%^CYAN%^Cl%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^uds%^RESET%^");
	set_id(({ "crown", "helm" }));
	set_short("%^BOLD%^%^WHITE%^C%^RESET%^r%^BOLD%^%^WHITE%^o%^RESET%^w%^BOLD%^%^WHITE%^n of %^BOLD%^%^CYAN%^Cl%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^d%^BOLD%^%^CYAN%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^flickering crown%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This unusual cr%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^wn entwines through the wearer's hair, clinging to it loosely. It seems to be made up of a %^RESET%^%^CYAN%^stran%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^, w%^RESET%^i%^BOLD%^%^CYAN%^spy substance, similar to %^BOLD%^%^WHITE%^white%^BOLD%^%^CYAN%^, fl%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^ffy %^BOLD%^%^WHITE%^clo%^RESET%^u%^BOLD%^%^WHITE%^ds%^BOLD%^%^CYAN%^. It constantly shifts shape, seeming to hold no particular form.


AVATAR
	);
	set_weight(3);
	set_value(5000);
	set_lore(
@AVATAR
This crown is said to be a gift of Akadi herself, given to free spirits and travellers. It is thought to be formed of clouds.

AVATAR
	);
	set_property("lore difficulty",3);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^A faint breeze blows through as "+ETOQCN+" wears the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel a light breeze tug playfully at your hair as you put the crown on.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" smiles faintly as the "+query_short()+" %^CYAN%^is set aside.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You already miss the breeze in your hair.%^RESET%^");
	return 1;
}

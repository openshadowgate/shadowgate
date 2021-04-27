#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^GREEN%^Gator hide armor%^RESET%^");
	set_id(({ "hide", "armor", "gator hide" }));
	set_short("%^RESET%^%^GREEN%^G%^BOLD%^a%^RESET%^%^GREEN%^t%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^-%^RESET%^%^GREEN%^hide Armor%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^t%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^g%^RESET%^%^GREEN%^h hide armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This thick but flexible armor has been made from the dense hide of a dire crocodile. The inseams are smooth and finished in a soft %^CYAN%^fish skin%^GREEN%^ of unknown origin but the the outer layer of the armor is rugged, thick and tough. The hide is thickest where it is designed to protect the shoulders and torso. It fits over the shoulders like a jacket, and clasps closed with polished %^BOLD%^%^WHITE%^croc teeth%^RESET%^%^GREEN%^.%^RESET%^ 

AVATAR
	);
	set_weight(30);
	set_value(4600);
	set_lore(
@AVATAR
%^RESET%^In many of the obscure tribes of sea elf, a young warrior must prove him or herself by hunting down a creature considered a threat to the community. Only the strongest and bravest of hunters would dare fight a dire crocodile alone. When this rare event occurs, the hide is often made into a flexible and waterproof armor as symbol of pride for the hero. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+" looks savage and well protected in the tough hide.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel the protected like a powerful beast!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+" looks vulnerable without their tough hide.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel vulnerable, now lacking your hide.%^RESET%^");
	return 1;
}

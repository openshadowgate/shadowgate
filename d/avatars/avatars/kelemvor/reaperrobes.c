#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Robes of the Reaper%^RESET%^");
	set_id(({ "robe", "robes" }));
	set_short("%^BOLD%^%^BLACK%^Robes of the Reaper%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Simple black robes%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The simple black robes drape over ones frame and a large black cowl can be drawn up over the head. There does not seem to be anything particularly special about them.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^These are the fabled robes of death. Simple to behold, yet a terrifying sight indeed. It is rumored that those who don these robes become death incarnate.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips into the robe and goes back to the eternal struggle of lost souls.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the robe and go back to the eternal struggle of lost souls.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips out of the robes, and looks quite relieved to be free of them.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip out of the robe, and feel the weight of the damned lift from your shoulders.%^RESET%^");
	return 1;
}

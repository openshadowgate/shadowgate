#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Fullplate of the dragon");
	set_id(({ "plate", " fullplate", " dragonplate" }));
	set_short("%^WHITE%^%^BOLD%^Fullplate of the %^GREEN%^Emerald Dragon%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A emerald green fullplate%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This heavy fullplate is a true masterpiece, the plate is forged out of mithral, and is covered in %^GREEN%^emerald scales%^WHITE%^ and on the front you can a incredible dragons head carved into the front of the armor.

AVATAR
	);
	set_weight(45);
	set_value(5000);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
	set_ac(8);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^WHITE%^%^BOLD%^"+ETO->query_cap_name()+" buckles up his fullplate",TP);
	tell_object(TP,"%^WHITE%^%^BOLD%^You buckle up the heavy plate, and feel reinsured by its protection");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^WHITE%^%^BOLD%^"+ETO->query_cap_name()+" removes his plate and lets out a sob",TP);
	tell_object(TP,"%^WHITE%^%^BOLD%^You remove the plate, and your body longs after its protection");
	return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("brooch of intellect");
	set_id(({ "brooch" }));
	set_short("%^BOLD%^%^BLACK%^Brooch %^BOLD%^%^BLUE%^of %^BOLD%^%^YELLOW%^Int%^RESET%^%^CYAN%^ell%^BOLD%^%^WHITE%^ect%^RESET%^");
	set_obvious_short("A %^BOLD%^%^CYAN%^crystal %^RESET%^brooch%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This crystal brooch fits over a cloak with ease and has a %^BOLD%^%^YELLOW%^golden %^BOLD%^%^CYAN%^pin that fastens it tight. The front of the brooch is a solid crystal which %^BOLD%^%^GREEN%^reflects %^BOLD%^%^CYAN%^light and %^BOLD%^%^BLACK%^darkens %^BOLD%^%^CYAN%^randomly.

AVATAR
	);
	set_weight(1);
	set_value(5000);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel yourself become more keen of your surroundings.");
	ETO->add_stat_bonus("intelligence",1);
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel yourself become less keen of your surroundings.");
	ETO->add_stat_bonus("intelligence",-1);
	ETO->set_property("magic resistance",-5);
	return 1;
}

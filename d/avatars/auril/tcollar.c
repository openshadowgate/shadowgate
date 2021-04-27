#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("tebryn collar");
	set_id(({ "collar" }));
	set_short("%^BOLD%^%^YELLOW%^Collar of %^BOLD%^%^BLACK%^Entrapment%^RESET%^");
	set_obvious_short("A steel collar");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This collar is made out a mithril material, and %^BOLD%^%^YELLOW%^energy %^BOLD%^%^RED%^courses across it. Studs stick from it which glow with magical energy. 

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",-5);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel the power clasp onto your neck, sending panic into you.");
	ETO->add_stat_bonus("charisma",-2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You finally are released of the collar, thank the gods.");
	ETO->add_stat_bonus("charisma",2);
	return 1;
}

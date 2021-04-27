#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shadow");
	set_id(({ "armor", "studded", "studded leather" }));
	set_short("%^BOLD%^%^BLACK%^Night's Cover%^RESET%^");
	set_obvious_short("studded leather");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This suit of studded armor is made up of boiled leather, with small metal discs covering parts of the armor. The leather is died a dark black, fading almost magically into the shadows that are nearby. %^BOLD%^%^YELLOW%^Runes %^BOLD%^%^BLACK%^can be seen covering the inside, and it is obviously quite enchanted.

AVATAR
	);
	set_weight(25);
	set_value(1000);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" wears the armor.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You eagerly don this armor, feeling at one with the shadows.");
	ETO->add_stat_bonus("dexterity",2);
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" removes the armor.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the armor carefully, and feel more connected to the real world.");
	ETO->add_stat_bonus("dexterity",-2);
	ETO->set_property("magic resistance",-5);
	return 1;
}

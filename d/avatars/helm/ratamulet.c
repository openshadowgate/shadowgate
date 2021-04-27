#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("amulet");
	set_id(({ "amulet" }));
	set_short("%^RESET%^%^ORANGE%^amulet of the rat%^RESET%^");
	set_obvious_short("a crude amulet made of brown fur");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a suspicious-looking amulet made of twigs, fur and straps of leather. It slightly resembles the head of a rodent where the twigs have been fastened as to make out the teeth.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("intelligence",-1);
	ETO->add_stat_bonus("constitution",-1);
	ETO->add_stat_bonus("charisma",-1);
	ETO->add_stat_bonus("dexterity",+1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("intelligence",1);
	ETO->add_stat_bonus("constitution",1);
	ETO->add_stat_bonus("charisma",1);
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}

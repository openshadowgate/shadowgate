#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jewelry");
	set_id(({ "jewelry", "gem", "chain" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^a mar%^RESET%^vello%^BOLD%^us %^RESET%^%^RED%^g%^BOLD%^e%^RESET%^%^RED%^m%^RESET%^ %^BOLD%^on a %^RESET%^silve%^BOLD%^%^BLACK%^r chain%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a mar%^RESET%^vello%^BOLD%^us %^RESET%^%^RED%^g%^BOLD%^e%^RESET%^%^RED%^m%^RESET%^ %^BOLD%^on a %^RESET%^silve%^BOLD%^%^BLACK%^r chain%^RESET%^");
	set_long(
@AVATAR
%^RED%^This wonderful piece of jewelry instantly draws your attention. On a silver chain rests a blood-red gem, gently clasped and held in place by thin strands of silver woven into a spiderweb. Inside the gem swirls a faint white mist and you can swear that you very briefly saw the outlines of a womans face in the centre of the gem.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1574);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^CYAN%^Your mind opens.%^RESET%^                                                                                                                   %^BOLD%^%^RED%^You gain more trust in yourself.%^RESET%^                                                                                       %^BOLD%^%^BLACK%^Your garments become heavier.%^RESET%^                                                                                           %^ORANGE%^You feel a slight lapse in judgement as you don the jewelry.%^RESET%^");
	ETO->add_stat_bonus("intelligence",2);
	ETO->add_stat_bonus("charisma",2);
	ETO->add_stat_bonus("strength",-1);
	ETO->add_stat_bonus("wisdom",-1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("intelligence",-2);
	ETO->add_stat_bonus("charisma",-2);
	ETO->add_stat_bonus("strength",1);
	ETO->add_stat_bonus("wisdom",1);
	return 1;
}

#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("flamberge");
	set_id(({ "flamberge", "sword", "weapon", "large sword", "blade" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^a magnificent flamberge%^RESET%^");
	set_obvious_short("a magnificent flamberge");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLUE%^This sword is six foot long with a black leather-wound hilt and a ricasso that reaches to about half its length. The other half consists of a sharp, wavy blade, pale white with a ghostly blue tint and etched with ancient letters in a flowing script. The cross-guard  is one foot wide with arms of dark metal wrought into unperceptible and seemingly changeable patterns.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
....%^BOLD%^%^BLACK%^Darthirii Caluss%^RESET%^
........%^RESET%^%^YELLOW%^[%^RESET%^Elf Eater%^YELLOW%^]%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(35);
	set_value(1643);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(1,10);
	set_large_wc(3,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ grabs the handle of a huge weapon and pulls it out of its sheath.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grab the handle and pull "+query_short()+"%^BOLD%^%^BLUE%^ out of its sheath on your back.%^RESET%^");
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ returns "+query_short()+"%^BOLD%^%^BLUE%^ to its sheath.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You return "+query_short()+"%^BOLD%^%^BLUE%^ to its sheath on your back.%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ grabs the ricasso with one hand and catches an attack.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grab the ricasso with one hand and catch "+targ->query_cap_name()+"%^BOLD%^%^BLUE%^'s attack.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ grabs the ricasso with one hand and catches your attack, you pull hard to get your weapon free.%^RESET%^");
		targ->set_paralyzed(roll_dice(2,6)+0);
return 0;	}
}
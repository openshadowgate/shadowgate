#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("flamberge");
	set_id(({ "flamberge", "sword", "two handed sword", "two hander", "weapon", "large sword", "elf eater", "elfeater", "caluss" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^a magnificent flamberge%^RESET%^");
	set_obvious_short("a magnificent flamberge");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLUE%^The very first thing that strikes anyone watching this blade is the size of it. The sword is six foot long with a black leather-wound hilt and a ricasso that reaches to about half its length. The other half consists of a sharp, wavy blade, pale white with a ghostly bluish tint and etched with a flowing old script. The cross-guard  is one foot wide with arms of wrought dark metal, twisting and turning in patterns unperceptible and seemingly changeable.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^Darthirii Caluss%^RESET%^
%^RESET%^%^YELLOW%^[%^RESET%^Elf Eater%^YELLOW%^]%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(30);
	set_value(1705);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ grabs the handle and slowly pulls the flamberge out of its sheath.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grab the handle and slowly slide the flamberge out of its sheath on your back.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ sheaths the sword in its scabbard.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You sheathe the sword in the scabbard on your back.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ runs "+targ->query_cap_name()+"%^BOLD%^%^BLUE%^ through with the "+query_short()+"%^BOLD%^%^BLUE%^ but seems to have trouble withdrawing it.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You run "+targ->query_cap_name()+"%^BOLD%^%^BLUE%^ through with your sword but have trouble withdrawing it as the blade suddenly becomes heavier. You have a sensation of hunger and you waver briefly as the sword feeds upon your opponents life force.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" runs you through with the "+query_short()+"%^BOLD%^%^BLUE%^ but seems have trouble withdrawing it. You have a sensation of loss and you scream in pain as the sword saps your life force.%^RESET%^");
		return roll_dice(2,8)+-1;	}
}
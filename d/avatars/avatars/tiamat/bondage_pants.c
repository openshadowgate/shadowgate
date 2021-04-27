#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bondage pants");
	set_id(({ "pants", "bondage pants" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^P%^RED%^a%^BLACK%^nts of B%^RED%^o%^BLACK%^ndage%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^leather bondage pants%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This is a pair of unusual legwear, some might describe them as pants.  They are made of slick black leather and, while covering the most private of bits, they leave bare flesh exposed in a provocative manner.  While technically pants, most of the material consists of straps and belts, some of which hang loosely around the legs.  The two largest straps flap towards the floor, ending in wickedly barbed buckles, stained with %^RED%^blood%^BLACK%^.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(900);
	set_lore(
@AVATAR
When the goddess of pain lost her rightful place in the Realms, some of her loyal clerics rebelled against their new god.  Some still remember the last of Loviatar's faithful parading through the town of Verbobone mutilating their own bodies by day and participating in dangerous orgies by night.  Some of the equipment used in these dark rituals remain as tasteless souvenirs of that strange time.  The occasional item is rumored to contain the last magical essence of the forsaken priests.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^"+ETOQCN+" %^BOLD%^%^BLACK%^looks very uncomfortable in the bondage pants.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^The straps of the bondage pants squeeze you in the worst places.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^"+ETOQCN+" %^BOLD%^%^BLACK%^breathes a sigh of relief, now free of the bondage pants.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^Your lower body relaxes now relieved of the bondage pants.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^%^BLACK%^A loose strap on the pants worn by "+ETOQCN+" %^BOLD%^%^BLACK%^lashes out at "+who->QCN+"%^BOLD%^%^BLACK%^!",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^A barbed strap on your bondage pants lashes out at "+who->QCN+"!%^RESET%^");
	tell_object(who,"%^RESET%^%^BOLD%^%^BLACK%^A strap on the bondage pants worn by "+ETOQCN+" %^BOLD%^%^BLACK%^lashes at you!!%^RESET%^");
		who->do_damage("torso",random(6));
return damage;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^massive iron sledgehammer%^RESET%^");
	set_id(({ "sledgehammer", "sledge", "hammer" }));
	set_short("%^BOLD%^%^BLACK%^massive iron sledgehammer%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^massive iron sledgehammer%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a massive hammer with a four foot long handle and an incredible metal iron head. It looks insanely heavy, but a blow from such a hammer would undoubtedly leave a mark. In fact, if one could swing it, it would be nigh unstoppable.%^RESET%^

AVATAR
	);
	set_weight(20);
	set_value(1000);
	set_lore(
@AVATAR
This heavy sledgehammer is a tool made by an old grumpy dwarven smith. He had a problem with heavily armored underdark critters -- Umber Hulks! So he made a weapon that would pierce their hide, and still be useful at the forge. It is said to retain some of the power of the forge.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bludgeoning");
	set_prof_type("large hammer");
	set_size(3);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" picks up a massive sledgehammer.",ETO);
	tell_object(ETO,"You pick up the massive hammer and feel its titannic weight.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" lets go of the massive sledgehammer.",ETO);
	tell_object(ETO,"You let the hammer go with some relief.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" crushes "+targ->QCN+" with a "+query_short()+"!!!%^RESET%^ "+query_short()+"!!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You crush "+targ->QCN+" with your "+query_short()+"!!!%^RESET%^");
	tell_object(targ,"%^RED%^You are crushed as "+ETOQCN+" smashes you with a "+query_short()+"!!!%^RESET%^");
		return roll_dice(3,10)+15;	}

}

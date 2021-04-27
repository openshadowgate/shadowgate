#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Sword of Knowledge");
	set_id(({ "sword" }));
	set_short("%^BOLD%^%^BLUE%^Sword of Knowledge");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is the legendary Sword of Knowledge.

AVATAR
	);
	set_weight(10);
	set_value(2147483647);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(normal);
	set_wc(15,30);
	set_large_wc(9,30);
	set_property("enchantment",15);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Knowledge seeps into "+ETOQCN+" when he wields "+query_short()+"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Knowledge seeps from "+query_short()+" into you.");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Knowledge leaves you when "+ETOQCN+" unwield "+query_short()+".",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Knowledge leaves you when you unwield "+query_short()+".");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),""+ETOQCN+" slashes and "+query_short()+" glows as it hits "+targ->QCN+"",({ETO,targ}));
	tell_object(ETO,""+query_short()+" glows as it hits "+targ->QCN+"");
	tell_object(targ,""+ETOQCN+" slashes and "+query_short()+" glows as it hits.");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}
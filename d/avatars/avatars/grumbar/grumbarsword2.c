#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("grumbarsword2");
	set_id(({ "earth sword", " sword" }));
	set_short("%^RESET%^%^ORANGE%^Sw%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^rd of D%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^st%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a dirt-coated sword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This sword is coated in a thick layer of dirt.  There is no visible clue as to how the dirt is staying on the sword, but it is.  The hilt is dirt-free but the leather grip is worn and frayed slightly.  A throbbing in your temple gets rhythmic as you continue to look at the sword.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
A gift from the earthen god to the earthly races!

AVATAR
	);
     set("langage","dwarvish");	set_weight(6);
	set_value(10000);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",10);
	set_ac(10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^goes into a hypnotic state as they wield "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The dirt on the "+query_short()+" seems to move, almost hypnotically.%^RESET%^");
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(5);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^blinks, their eyes clear up, and they seem to be conscious of their surroundings as they release the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The dirt on the "+query_short()+" stops moving as you unwield it.%^RESET%^");
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-5);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^A %^BOLD%^%^ORANGE%^pound of dirt %^RESET%^%^ORANGE%^tries to fill the wound left on %^BOLD%^%^MAGENTA%^"+targ->QCN+" %^RESET%^%^ORANGE%^as %^BOLD%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^strikes them with the "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^A %^BOLD%^%^ORANGE%^pound of dirt %^RESET%^%^ORANGE%^tries to fill the wound left on %^BOLD%^%^MAGENTA%^"+targ->QCN+" %^RESET%^%^ORANGE%^as the "+query_short()+" strikes them with suredness!%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^The place %^BOLD%^%^ORANGE%^"+query_short()+" %^RESET%^%^ORANGE%^strikes you feels like it is filling with a %^BOLD%^%^ORANGE%^pound of dirt %^RESET%^%^ORANGE%^as %^BOLD%^%^MAGENTA%^"+ETOQCN+" %^RESET%^%^ORANGE%^strikes you with it!%^RESET%^");
		return roll_dice(3,20)+0;	}
}
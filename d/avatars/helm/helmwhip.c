#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip", "helm's whip", "weapon" }));
	set_short("%^RESET%^%^YELLOW%^scourge whip of unspeakable pain%^RESET%^");
	set_obvious_short("%^RESET%^%^YELLOW%^scourge whip of unspeakable pain%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^YELLOW%^This is a beautiful nasty-looking scourge whip with lots of strands with lots of nasty barbed metal things at the ends.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("helm's whip");
	set_size(2);
	set_wc(10,20);
	set_large_wc(10,20);
	set_property("enchantment",4);
	set_ac(370);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^RESET%^%^YELLOW%^"+ETO->query_cap_name()+"%^RESET%^%^YELLOW%^'s eyes light up as you wield the whip.%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^Your eyes light up as you wield the whip.%^RESET%^");
	ETO->add_damage_bonus(100);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^RESET%^%^YELLOW%^"+ETO->query_cap_name()+"%^RESET%^%^YELLOW%^ sighs as he releases the whip.%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^You sigh as you release the whip.%^RESET%^");
	ETO->add_damage_bonus(-100);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 800){
	tell_room(environment(query_wielded()),"%^RESET%^%^YELLOW%^"+ETO->query_cap_name()+"%^RESET%^%^YELLOW%^ beats the crap out of "+targ->query_cap_name()+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^YELLOW%^You beat the living crap out of "+targ->query_cap_name()+".%^RESET%^");
	tell_object(targ,"%^RESET%^%^YELLOW%^"+ETO->query_cap_name()+"%^RESET%^%^YELLOW%^ beats the crap out of you.%^RESET%^");
		return roll_dice(10,10)+2;	}
}
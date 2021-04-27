#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Nature's Wrath");
	set_id(({ "sword", "wrath", "Sword", "Wrath", "Natures Sword", "Nature's Sword", "natures sword", "nature's sword", "Nature's Wrath", "Natures Wrath", "nature's wrath", "natures wrath" }));
	set_short("%^BOLD%^%^GREEN%^Nature's Wrath%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^Nature's Wrath%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This weapon is made from a translucent glowing green material.  It is obviously not naturally from this world.  It has been assembled to deliver the vengeful wrath of nature on anyone who dares harm the natural world.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(100000000);
	set_type("slashing");
	set_prof_type("wrath sword");
	set_size(1);
	set_wc(100,100);
	set_large_wc(100,100);
	set_property("enchantment",30);
	set_ac(400);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" takes it upon himself to deliver "+query_short()+"%^GREEN%^!%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^You take it upon yourself to deliver "+query_short()+"%^GREEN%^!%^RESET%^");
	TP->add_attack_bonus(400);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" rids himself of "+query_short()+"%^GREEN%^!%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^You have avenged nature and rid yourself of it's wrath.%^RESET%^");
	TP->add_attack_bonus(-400);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^GREEN%^"+ETO->query_cap_name()+" strikes "+targ->query_cap_name()+" with "+query_short()+"%^GREEN%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^GREEN%^You strike "+targ->query_cap_name()+" with "+query_short()+"%^GREEN%^!%^RESET%^");
	tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+" strikes you with "+query_short()+"%^GREEN%^!%^RESET%^");
		targ->set_paralyzed(roll_dice(10,10)+10);
return 0;	}
}
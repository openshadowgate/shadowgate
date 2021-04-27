#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RED%^Blade of Hate");
	set_id(({ "dagger", "blade" }));
	set_short("%^BOLD%^%^RED%^Blade of Hate%^RESET%^");
	set_obvious_short("%^RED%^a long dagger, with ancient runes carved into the blade%^RESET%^");
	set_long(
@AVATAR
%^RED%^The ancient blade, can only be wielded by true evil.

AVATAR
	);
	set_weight(200);
	set_value(500000000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(40,20);
	set_large_wc(40,40);
	set_property("enchantment",15);
	set_ac(120);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,""+TP->query_cap_name()+" screams out as he wields the blade",TP);
	tell_object(TP,"%^RED%^The blade carves into your skin as you try to wield it");
	TP->do_damage("torso",random(500));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" sends out a sigh of relief as he unwields the blade",TP);
	tell_object(TP,"%^RED%^You unwield the blade with a sigh, and your wounds heal");
	TP->do_damage("torso",random(-500));
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 600){
	tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+" hit the "+targ->query_cap_name()+" and it screams out in pain",({ETO,targ}));
	tell_object(ETO,"%^RED%^You hit the "+targ->query_cap_name()+" and it screams out in pain");
	tell_object(targ,"%^RED%^"+ETO->query_cap_name()+" hits you and you scream out in pain");
		return roll_dice(20,30)+0;	}
}
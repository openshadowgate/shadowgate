#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ebon sword");
	set_id(({ "sword", "longsword", "ebon sword", "ebon longsword", "ebony longsword", "ebony sword" }));
	set_short("%^BOLD%^%^BLACK%^Ebony Longsword%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^ebony longsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This weapon is made from some type of ebon metal, crafted to utter perfection.  It extends nearly three free from the pommel with a razor sharp edge.  Strangely this weapon shows no signs of damage and has no visible blimishes, obviously the work of magic.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",3);
	set_ac(-1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->query_cap_name()+"'s%^BOLD%^%^BLACK%^ grins %^RED%^evilly%^RESET%^%^BOLD%^%^BLACK%^ and grasps the hilt of the "+query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^With a evil grin you grab the hilt of the "+query_short()+"%^BOLD%^%^BLACK%^ and feel a surge of raw %^RED%^energy!%^RESET%^");
	TP->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->query_cap_name()+" %^BOLD%^%^BLACK%^sighs and releases the "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^With a sigh you release the hilt of the "+query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^");
	TP->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s%^BOLD%^%^BLACK%^ "+query_short()+"%^BOLD%^%^BLACK%^ glows as it strikes "+targ->query_cap_name()+"!%^BOLD%^%^BLACK%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel weakened as your "+query_short()+"%^BOLD%^%^BLACK%^ slashes into "+targ->query_cap_name()+"%^BOLD%^%^BLACK%^!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s %^BOLD%^%^BLACK%^"+query_short()+"%^BOLD%^%^BLACK%^ glows at it slashes into you!%^RESET%^");
		return roll_dice(1,2)+1;	}
}
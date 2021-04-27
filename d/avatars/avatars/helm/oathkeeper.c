#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "sword", "longsword", "long sword", "kabad", "oathkeeper", "keeper", "oath keeper", "weapon" }));
	set_short("%^BOLD%^%^BLACK%^O%^RESET%^ath%^BOLD%^%^BLACK%^K%^RESET%^eeper");
	set_obvious_short("an old longsword");
	set_long(
@AVATAR
At a first glance this blade appears to be nothing else than an old sword, worn by time and stripped of any markings and symbols that could identify it as anything else. It is surprisingly well cared for as the edges of the blade are sharp and true and there are no signs of either corrosion or discoloring on the weapon. It appears to be made of steel with a cruciform hilt and a grip wound with leather that has darkened with age to a blackish brown color.

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",3);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The outlines of a raised plate gauntlet slowly appear against the base of the hilt on "+ETOQCN+"%^BOLD%^%^BLACK%^'s sword.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you grab the sleek handle you feel it throb in tune with your heartbeats. %^RESET%^                                                                                                                                               %^BOLD%^%^BLACK%^The outlines of a raised plate gauntlet appear against the base of the hilt.%^RESET%^                                                                                                                                                     %^CYAN%^A voice in your mind speaks: %^BOLD%^%^BLACK%^ 'Kabad I am, keeper of oaths: Truest of blades, wielded by many: Yet as they pass, I will remain: Keeper I am, Kabad my name'%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The outlines of a plate gauntlet slowly fade away from the hilt of "+ETOQCN+"'s sword.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Reluctantly you let go of the sword.%^RESET%^                                                                                                                                                               %^BOLD%^%^BLACK%^The plate gauntlet visible against the base of the hilt slowly fades away. %^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 600){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The edges of "+ETOQCN+"'s sword glow with a pale gray light as it cuts through "+targ->QCN+"'s defenses.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The edges of your sword glow with a pale gray light as it cuts through your opponent's defenses.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^The edges of "+ETOQCN+"'s sword glow with a pale gray light as it cuts through your defenses.%^RESET%^");
		return roll_dice(1,8)+0;	}
}
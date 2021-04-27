#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("diamond blade");
	set_id(({ "sword", "diamond sword", "blade", "diamond blade", "weapon" }));
	set_short("%^BOLD%^%^WHITE%^D%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d Blade%^RESET%^");
	set_obvious_short("longsword");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This weapon is almost four feet in length, and is made entirely from a shard of %^BLUE%^sky blue %^BOLD%^%^WHITE%^d%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d. It has been excellently crafted to fit the hands of a warrior, as it is perfectly balanced and lethally sharp. Despite this, it looks as if it has never saw battle.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(1000);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,4);
	set_large_wc(3,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" readies the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You ready your "+query_short()+"%^RESET%^");
	TP->add_stat_bonus("strength",1);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" lowers the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You lower your "+query_short()+"%^RESET%^");
	TP->add_stat_bonus("strength",-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The "+query_short()+" wielded by "+ETO->query_cap_name()+" glows %^YELLOW%^brilliantly%^BOLD%^%^WHITE%^ as it comes into contact with "+targ->query_cap_name()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The "+query_short()+" glows brilliantly as it comes into contact with "+targ->query_cap_name()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^You are momentarily stunned by the brilliant %^YELLOW%^glow%^BOLD%^%^WHITE%^ which comes forth from the "+query_short()+" wielded by "+ETO->query_cap_name()+"!%^RESET%^");
		targ->set_paralyzed(roll_dice(1,3)+1);
return 0;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("diamond shard");
	set_id(({ "shard", "diamond shard", "sword", "shortsword", "short sword", "diamond shortsword" }));
	set_short("%^BOLD%^%^WHITE%^D%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d Shard%^RESET%^");
	set_obvious_short("shortsword");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This weapon roughly two feet in length, and is made entirely from a shard of %^BLUE%^sky blue %^BOLD%^%^WHITE%^D%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d.  It has been excellently crafted to fit the hands of a warrior, as it is perfectly balanced and lethally sharp.  Despite this, it looks as if it has never saw battle.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" readies the "+query_short()+".%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You ready your "+query_short()+".%^RESET%^");
	TP->add_damage_bonus(4);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->query_cap_name()+" lowers the "+query_short()+".%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You lower your "+query_short()+"%^RESET%^");
	TP->add_damage_bonus(-4);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+"'s "+query_short()+" glows a fiery red as it strikes "+targ->query_cap_name()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your "+query_short()+" glows a %^RED%^fiery red%^BOLD%^%^WHITE%^ as it strikes "+targ->query_cap_name()+"!%^RESET%^");
	tell_object(targ,"%^RED%^"+ETO->query_cap_name()+"'s "+query_short()+" glows a fiery red as it strikes you, scorching your flesh!%^RESET%^");
		return roll_dice(3,4)+0;	}
}
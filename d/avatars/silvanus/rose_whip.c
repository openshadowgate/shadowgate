#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("rose whip");
	set_id(({ "whip", "rose whip", "thorn whip", "whip of thorns", "thorny rose whip" }));
	set_short("%^GREEN%^Whip of Thorns%^RESET%^");
	set_obvious_short("%^GREEN%^whip of thorns%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This whip is made from a supple green leather that feels much like %^MAGENTA%^velvet%^RESET%^%^GREEN%^, with minature %^BOLD%^%^BLACK%^barbed%^RESET%^%^GREEN%^ rose vines woven into the braid of it.  Two small %^RED%^red%^GREEN%^ roses are in bloom near the handle of the whip, as the rest have fallen apart and became scattered, a few of the petals hanging carelessly within the braid of the whip, probably as a result of frequent use.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(20);
	set_type("slashing");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,2);
	set_large_wc(1,3);
	set_property("enchantment",2);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+"%^GREEN%^ carefully grabs the handle of the "+query_short()+"%^GREEN%^.%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^Carefully you grab the handle of the "+query_short()+"%^GREEN%^.");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^GREEN%^While releasing the "+query_short()+"%^GREEN%^ "+TP->query_cap_name()+"%^GREEN%^ is cut by one of its thorns!%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^Releasing the handle of the "+query_short()+"%^GREEN%^ you %^RED%^cut%^RESET%^%^GREEN%^ yourself on one of its thorns!%^RESET%^");
	TP->do_damage("torso",random(2));
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^GREEN%^"+ETO->query_cap_name()+"'s%^GREEN%^ "+query_short()+"%^GREEN%^ draws blood as it strikes "+targ->query_cap_name()+"%^GREEN%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^GREEN%^Your "+query_short()+"%^GREEN%^ slashes across "+targ->query_cap_name()+"'s%^GREEN%^ flesh, drawing blood!%^RESET%^");
	tell_object(targ,"%^GREEN%^"+ETO->query_cap_name()+"'s %^GREEN%^"+query_short()+"%^GREEN%^ draws blood as it strikes you!%^RESET%^");
		return roll_dice(1,4)+0;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ironshod staff");
	set_id(({ "staff", "ironshod staff", "weapon" }));
	set_short("%^RESET%^%^ORANGE%^ironshod staff%^RESET%^");
	set_obvious_short("ironshod staff");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a simle and sturdy wooden staff where a sharp and nasty spike of iron has been fitted to each end. Several metal bands are fastened around the length of the staff to prevent the wood splintering too easily. For a travellers tool it sees many uses and thugs know to stay well away of the wielder.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(134);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",1);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->add_damage_bonus(2);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->add_damage_bonus(-2);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" %^RESET%^%^ORANGE%^hits "+targ->query_cap_name()+"%^RESET%^%^ORANGE%^ over the head with the staff.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hit your victim over the head with your staff.%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" %^RESET%^%^ORANGE%^hits you over the head.%^RESET%^");
		targ->set_paralyzed(roll_dice(4,0)+0);
return 0;	}
}
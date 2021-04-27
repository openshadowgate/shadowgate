#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("claw");
	set_id(({ "claw", "tigerclaw", "tiger claw", "bagh nakh", "weapon" }));
	set_short("%^RESET%^%^ORANGE%^Bagh nakh%^RESET%^");
	set_obvious_short("Tiger claw");
	set_long(
@AVATAR
In all its simplicity this weapon consists of a metal bar from which four sharp and curved blades of steel extend. You wear it by slipping your pinkie and forefinger through the loops on the top of the bar and then, by grasping it firmly in your palm, you shred someone.

AVATAR
	);
	set_weight(1);
	set_value(26);
	set_lore(
@AVATAR
This weapon is favoured by the assassins and thieves in the eastern parts of the vast Tsarvani empire. The wounds closely resembles that of the large tiger which is a fairly common cause of death in that particular part of the realms.

AVATAR
	);
	set_property("lore difficulty",6);
	set_type("slashing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^You slip your fingers through the loop and grasp the "+query_short()+"%^RESET%^%^RED%^ firmly.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^You slip the "+query_short()+"%^RESET%^%^RED%^ off your fingers.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+" rends "+targ->QCN+" badly!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^You rend your opponent badly!%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+" rends you badly!%^RESET%^");
		return roll_dice(1,6)+0;	}
}
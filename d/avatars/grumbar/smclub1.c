#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("small oak club");
	set_id(({ "small club", "club", "oak club", "small oak club" }));
	set_short("Small oak club");
	set_obvious_short("small club");
	set_long(
@AVATAR
A small club made from black oak. Its smooth hard surface glistens from what may be years of use.

AVATAR
	);
	set_weight(5);
	set_value(50);
	set_type("bludgeoning");
	set_prof_type("clublike");
	set_size(1);
	set_wc(1,8);
	set_large_wc(1,6);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"The "+query_short()+" makes a loud crack as "+ETO->query_cap_name()+" smacks "+targ->query_cap_name()+" with it.",({ETO,targ}));
	tell_object(ETO,"The "+query_short()+" makes a loud crack as it smacks "+targ->query_cap_name()+".");
	tell_object(targ,"The "+query_short()+" makes a loud crack as "+ETO->query_cap_name()+" hits you with with it.");
		return roll_dice(1,4)+0;	}
}
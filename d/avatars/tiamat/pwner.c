#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ubar pwner");
	set_id(({ "pwner" }));
	set_short("pwner");
	set_obvious_short("pwner");
	set_long(
@AVATAR
The pwner does not need a describe.  It doesn't even need color.  Suck.

AVATAR
	);
	set_weight(1);
	set_value(1000000000);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(75,50);
	set_large_wc(75,50);
	set_property("enchantment",7);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"You're about to die.",ETO);
	tell_object(ETO,"You're about to die.");
	return 1;
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"Suck",({ETO,targ}));
	tell_object(ETO,"You're going to win");
	tell_object(targ,"Suck");
		return roll_dice(30,30)+0;	}

}

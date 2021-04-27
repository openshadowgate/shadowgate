#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("testing111");
	set_id(({ "sword", "weapon" }));
	set_short("testing shit");
	set_long(
@AVATAR
A test damn it!!!!

AVATAR
	);
	set_weight(1);
	set_value(5);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(5,5);
	set_large_wc(5,5);
	set_property("enchantment",3);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"BLAH!!!!",({ETO,targ}));
	tell_object(ETO,"BLAH!!!!");
	tell_object(targ,"BLAH!!!!");
		return roll_dice(5,1)+-1;	}
}
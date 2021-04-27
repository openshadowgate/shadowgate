#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("a stupid sword");
	set_id(({ "sword" }));
	set_short("a stupid sword");
	set_obvious_short("a really stupid sword");
	set_long(
@AVATAR
This sword looks really stupid

AVATAR
	);
	set_weight(1);
	set_value(2);
	set_type("slashing");
	set_prof_type("small blade");
	set_size(2);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
	set_ac(2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"ouch",({ETO,targ}));
	tell_object(ETO,"ouch");
	tell_object(targ,"ouch");
		return roll_dice(3,4)+-1;	}
}
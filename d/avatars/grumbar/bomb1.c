#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("small explosive");
	set_id(({ "bomb", "small explosive", "explosive" }));
	set_short("a small explosive device");
	set_obvious_short("a small metal ball");
	set_long(
@AVATAR
testing

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
testing

AVATAR
	);
	set_property("lore difficulty",21);
	set_type("piercing");
	set_prof_type("tool");
	set_size(small);
	set_wc(1,100);
	set_large_wc(1,100);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"test",({ETO,targ}));
	tell_object(ETO,"test");
	tell_object(targ,"test");
		targ->set_paralyzed(roll_dice(1,6)+0);
return 0;	}
}
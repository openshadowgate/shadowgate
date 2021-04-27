#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "special sword", " sword", " longsword", " long", " long sword" }));
	set_short("Special sword");
	set_long(
@AVATAR
This is a longsword that should special 50 percent of the time, doing extra damage.

AVATAR
	);
	set("read",
@AVATAR
*

AVATAR
	);
	set_weight(5);
	set_value(15);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^Special!!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^Special!!");
	tell_object(targ,"%^BOLD%^Special!!");
		return roll_dice(4,2)+1;	}
}
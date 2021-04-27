#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "sword", " special sword" }));
	set_short("Longsword");
	set_long(
@AVATAR
This is a longsword that has a small chip in the blade.

AVATAR
	);
	set_weight(15);
	set_value(15);
	set_lore(
@AVATAR


AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^Special!!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^Special!!");
	tell_object(targ,"%^BOLD%^Special!!");
		return roll_dice(2,6)+10;	}
}
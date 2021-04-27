#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("demclaw");
	set_id(({ "claw" }));
	set_short("%^BOLD%^%^BLACK%^Long curved black claws%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Long curved black claws%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(250);
	set_value(0);
	set_type("slashing");
	set_prof_type("claw");
	set_size(3);
	set_wc(4,6);
	set_large_wc(4,6);
	set_property("enchantment",5);
	set_ac(20);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^BOLD%^%^RED%^The creature rends through you with his claw!");
		return roll_dice(3,6)+0;	}
}
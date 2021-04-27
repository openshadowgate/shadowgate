#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("claws");
	set_id(({ "claws" }));
	set_short("%^ORANGE%^wolf claws%^RESET%^");
	set_obvious_short("%^ORANGE%^wolf claws%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is an imm-only object for use in killing players.  If this ends up in your possession, please offer it or ask for an imm to take it away.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("dagger");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^ORANGE%^"+ETOQCN+" howls as she swipes at her prey!",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^You howl as you swipe at your prey!");
	tell_object(targ,"%^ORANGE%^The wolf howls as she swipes at you, deadening your senses!");
		targ->set_paralyzed(roll_dice(20,0)+0);
return 0;	}

}

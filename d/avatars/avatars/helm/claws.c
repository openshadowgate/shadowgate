#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("claws");
	set_id(({ "claws" }));
	set_short("%^RESET%^%^RED%^dragon claws%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^dragon claws%^RESET%^");
	set_long(
@AVATAR
These are the sharp claws of a mighty red dragon.

AVATAR
	);
	set_weight(40);
	set_value(0);
	set_type("slashing");
	set_prof_type("dragon claws");
	set_size(2);
	set_wc(2,8);
	set_large_wc(2,8);
	set_property("enchantment",-1);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 800){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^The dragon rends %^RESET%^%^RED%^"+targ->query_cap_name()+" %^RESET%^%^RED%^badly.",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"%^RESET%^%^RED%^The dragon rends you badly with its claws!%^RESET%^");
	}
}
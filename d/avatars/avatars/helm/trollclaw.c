#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Troll's claws");
	set_id(({ "claws" }));
	set_short("%^RESET%^%^GREEN%^Troll's claws");
	set_long(
@AVATAR
These are the sharp claws of a troll.

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_type("slashing");
	set_prof_type("troll claws");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),""+ETO->query_cap_name()+" guts "+targ->query_cap_name()+" with it's "+query_short()+".",({ETO,targ}));
	tell_object(ETO,"You gut the "+targ->query_cap_name()+" with your claws.");
	tell_object(targ,""+ETO->query_cap_name()+" guts you with it's "+query_short()+".");
		return roll_dice(1,4)+-1;	}
}
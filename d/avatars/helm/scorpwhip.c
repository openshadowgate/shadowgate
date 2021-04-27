#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip", "scorpion whip", "weapon" }));
	set_short("%^RESET%^%^ORANGE%^Scorpion whip%^RESET%^");
	set_obvious_short("A nasty bullwhip");
	set_long(
@AVATAR
This weapon looks quite the same as an ordinary bullwhip except that the very end of the whip resembles a vicious scorpion stinger. It is made out of quality hide, plaited and treated with skill. It appears to be well made.

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_type("slashing");
	set_prof_type("whip");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+"'s aim is true and the stinger sinks into the flesh of "+targ->QCN+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^Your aim is true and the stinger sinks into the flesh of your opponent.%^RESET%^");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+"'s aim is true and the stinger sinks into your flesh.%^RESET%^");
		return roll_dice(1,6)+0;	}
}
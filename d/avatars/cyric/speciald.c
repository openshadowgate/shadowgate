#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("special dagger");
	set_id(({ "dagger", " special dagger" }));
	set_short("Dagger");
	set_obvious_short("dagger");
	set_long(
@AVATAR
This is a dagger with a sharp edge.  It should give you a special half of the time.

AVATAR
	);
	set_weight(1);
	set_value(1);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^The "+query_short()+" wielded by "+ETO->query_cap_name()+" glows bright as it pierces "+targ->query_cap_name()+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^Your dagger glows brightly, doing extra damage!");
	tell_object(targ,"%^BOLD%^The dagger wielded by "+ETO->query_cap_name()+" glows bright as it hits you!");
		return roll_dice(1,4)+1;	}
}
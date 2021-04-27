#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Ghoul Blade");
	set_id(({ "dagger", "blade", "weapon", "ghoul blade" }));
	set_short("%^BOLD%^%^BLACK%^Ghoul blade%^RESET%^");
	set_obvious_short("dark dagger");
	set_long(
@AVATAR
This dagger is wrought from a mysterious dark metal. The blade is somewhat stained and corroded as if it has not been taken cared of very well for some unknown length of time. The bone hilt, carved in the likeness of skeletal fingers, has now aged to a dull yellow color.

AVATAR
	);
	set_weight(3);
	set_value(233);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^'Forged from the bone of dead warriors' and 'enchanted with the spirits of the wandering ghouls' are all words that describe these daggers of shadows. None of the above statements are true but nevertheless blades like these sometimes find their way to the surface where they are highly valued among the shadowkin rouges.

AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"%^BOLD%^%^BLACK%^ grabs the dagger and blinks a few times.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You grab the dagger by the hilt and feel something briefly intrude into your consciousness.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" releases the dagger and blinks a few times.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You release the dagger and the presence in your mind disappears.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"%^BOLD%^%^BLACK%^ stabs the dagger deeply into his victim.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You stab the dagger deeply into your victim.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" stabs the dagger deeply into you.%^RESET%^");
		return roll_dice(1,4)+0;	}
}
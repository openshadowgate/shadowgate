#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ghoul touch");
	set_id(({ "touch", "ghoul touch", "hand" }));
	set_short("%^MAGENTA%^ghoul's touch%^RESET%^");
	set_obvious_short("%^MAGENTA%^ghoul's touch%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^ghoul's touch, for use on a monster, not to be used for equipping elsewhere.  Please destroy if found.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("slashing");
	set_prof_type("claws");
	set_size(2);
	set_wc(3,4);
	set_large_wc(3,4);
	set_property("enchantment",0);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^MAGENTA%^The ghoul lashes out at "+targ->QCN+" with its claws!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"You lash out with your ghoul touch");
	tell_object(targ,"%^MAGENTA%^The ghoul lashes out at you with its claws!%^RESET%^");
		targ->set_paralyzed(roll_dice(15,0)+0);
return 0;	}

}

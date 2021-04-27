#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shark teeth");
	set_id(({ "teeth", "shark teeth" }));
	set_short("%^BOLD%^%^WHITE%^razor sharp shark teeth%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^razor sharp shark teeth%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^razor sharp shark teeth%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("piercing");
	set_prof_type("teeth");
	set_size(2);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" clamps down hard upon "+targ->QCN+" and tears a great gash of flesh from their side!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You clamp down hard upon "+targ->QCN+" and tear a great gash of flesh from their side!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" clamps down hard upon you and tears a great gash of flesh from your side!%^RESET%^");
		return roll_dice(4,3)+1;	}

}

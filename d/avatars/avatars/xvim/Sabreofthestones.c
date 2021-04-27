#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^GREEN%^Sabre of the %^BLUE%^stones%^RESET%^");
	set_id(({ "sabre", "sword" }));
	set_short("%^GREEN%^Sabre of the %^BLUE%^stones%^RESET%^");
	set_obvious_short("%^GREEN%^a huge sabre with a %^BLUE%^blue%^GREEN%^ blade%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This long curved sword is simply huge, the hilt itself is made out of several %^RED%^differently shaped colorfull stones%^GREEN%^ and they glow brightly in the %^YELLOW%^daylight sun.%^GREEN%^ One should think it would be slippery, but the small edges on the rocks, make it have a very solid grip. The blade itself is made out of a darkblue metal that seems not to reflect any light off the surface, wieght and power is more important when using this sword, than its sharpness

AVATAR
	);
	set_weight(30);
	set_value(2000);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(3,6);
	set_large_wc(2,6);
	set_property("enchantment",2);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^GREEN%^The blade cuts into "+targ->query_cap_name()+" deeply and leaves a huge wound",({ETO,targ}));
	tell_object(ETO,"%^GREEN%^The blade cuts into "+targ->query_cap_name()+" deeply and leaves a huge wound");
	tell_object(targ,"%^GREEN%^The blade cuts into you deeply and leaves a huge wound");
		return roll_dice(3,4)+-1;	}
}
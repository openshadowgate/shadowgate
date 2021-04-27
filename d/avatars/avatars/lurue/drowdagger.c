#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger", "drow dagger", "curved dagger" }));
	set_short("%^BOLD%^%^BLACK%^C%^RED%^u%^BLACK%^rved T%^RED%^a%^BLACK%^lon%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a curved dagger made of glass%^RESET%^");
	set_long(
@AVATAR
This curved dagger looks incredibly sharp and dangerous.  Made from some form of %^BOLD%^%^BLACK%^black glass %^RESET%^like material and wrapped in %^BOLD%^%^RED%^red leather%^RESET%^, it gleams in the light and seems to draw the light in.  A wicked looking weapon indeed.

AVATAR
	);
	set_weight(2);
	set_value(200);
	set_lore(
@AVATAR
Some drow favor naturally made weapons, claiming that they are part of the underdark and so hold the power of their home.  Making the weapon truly superior.  Some even go so far as to have these weapons enchanted.  Those that find them on the surface claim that they are fine weapons indeed.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("dagger");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^BLACK%^ cuts deep into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You "+query_short()+"%^BOLD%^%^BLACK%^ cuts deep into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^BLACK%^ cuts deep into you!%^RESET%^");
		return roll_dice(1,4)+1;	}
}
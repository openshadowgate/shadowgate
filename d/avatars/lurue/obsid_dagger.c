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
This curved dagger looks incredibly sharp and dangerous.  Made form some form of %^BLACK%^%^BOLD%^black glass%^RESET%^ like material, the hilt has been wrapped in %^BOLD%^%^RED%^red leather%^RESET%^ that is soft and textured for a firm grip.  The glass gleams in the light but also seems to draw the light in to its core.  It is a wicked looking weapon indeed.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(200);
	set_lore(
@AVATAR
Some drow favor weapons made from the natural elements of their home.  They claim this is because it inhabits the energies of the underdark better and thus makes a finer weapon.  Some even go so far as to enchant their weapons to make them even stronger during battle.  Those few that have been found on the surface, or recovered from the darkness, are known to be fine weapons.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
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
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" darts forward and feinst to the left, then strike quickly into "+targ->QCN+"'s right side with their "+query_short()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You dart forward and feint to the left, then strike quickly into "+targ->QCN+"'s right side with your "+query_short()+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" darts forward and feints to the left, then strike quickly into your right side with their "+query_short()+"!%^RESET%^");
		return roll_dice(1,4)+1;	}
}
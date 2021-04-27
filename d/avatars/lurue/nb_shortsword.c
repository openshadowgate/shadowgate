#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("short sword");
	set_id(({ "shortsword", "sword", "short sword" }));
	set_short("%^BOLD%^%^BLACK%^a g%^BLUE%^r%^BLACK%^ay%^BLUE%^i%^BLACK%^sh-b%^BLUE%^l%^BLACK%^u%^BLUE%^e%^BLACK%^ shortsword%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a g%^BLUE%^r%^BLACK%^ay%^BLUE%^i%^BLACK%^sh-b%^BLUE%^l%^BLACK%^u%^BLUE%^e%^BLACK%^ shortsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This curious g%^BLUE%^r%^BLACK%^ay%^BLUE%^i%^BLACK%^sh-b%^BLUE%^l%^BLACK%^u%^BLUE%^e%^BLACK%^ shortsword is made from some unknown material, but seems incredibly sharp and strong for its small frame.  Wrapped in what appears to be some sort of leathery material, the hilt is slightly spongy and produces a firm grip.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(50);
	set_type("slashing");
	set_prof_type("short blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,4);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The "+query_short()+"%^BOLD%^%^BLACK%^ in "+query_short()+"'s hands begins to vibrate and shudder as they stab "+targ->QCN+", ripping and tearing at "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The "+query_short()+"%^BOLD%^%^BLACK%^ in your hands begins to vibrate and shudder as you stab "+targ->QCN+", ripping and tearing at their flesh!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^The "+query_short()+"%^BOLD%^%^BLACK%^ in "+query_short()+"'s hands begins to vibrate and shudder as they stab you, ripping and tearing at your flesh!%^RESET%^");
		targ->set_paralyzed(roll_dice(2,0)+0);
return 0;	}
}
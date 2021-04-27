#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("golem blade");
	set_id(({ "blade" }));
	set_short("%^BOLD%^%^BLACK%^A six foot long blade which extends from each hand%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A six foot long blade which extends from each hand%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A massive six foot blade which is fused with the rest of the hand.

AVATAR
	);
	set_weight(100);
	set_value(0);
	set_type("slashing");
	set_prof_type("giant blade");
	set_size(3);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",5);
	set_ac(18);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" grabs "+targ->QCN+" violently by the head and lifts him high off the ground. Struggling against the grip, "+targ->QCN+" tries futilely to get away. All of a sudden "+ETOQCN+" punches its fist through "+targ->QCN+"'s chest with its massive blade and %^RESET%^%^RED%^blood %^BOLD%^%^RED%^flies out "+targ->QCN+"'s back. With a jerk, "+ETOQCN+" rips upward, cutting "+targ->QCN+" in two, spraying %^RESET%^%^RED%^blood %^BOLD%^%^RED%^high into the air. "+targ->QCN+"'s two halves collapse to the ground in two bloody heaps.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You lift your opponent up and cut them in two.");
	tell_object(targ,"%^BOLD%^%^RED%^You fight hard against the Golem, attacking as best you can. Suddenly the Golem grabs you by the head and lifts you into the air. Struggling against its firm grasp you attempt to break free but fail. Suddenly you feel intense %^BOLD%^%^BLACK%^pain %^BOLD%^%^RED%^as a massive blade is shoved through your body. You feel blood rush into your mouth from your lungs and you look down to see the blade cutting your body from the center up towards your head. As it hits your throat it throws your head back and you see your %^RESET%^%^RED%^blood %^BOLD%^%^RED%^fly into the air above you. With your last sensory receptions you see the ground hurdling towards you and then everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^RED%^.");
		return roll_dice(50,20)+0;	}
}
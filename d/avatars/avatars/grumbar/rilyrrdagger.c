#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Dagger of Orlytyl");
	set_id(({ "dagger" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^an ethereal blade%^RESET%^");
	set_obvious_short("a small dagger");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This blade of this dagger is made from a wonderous looking metal.  It is indescribable and has not been seen in this realm before.  The hilt is wrapped with the thin, dark tendon of some beast from the underdark.  It is light and feels extremely balanced as you toss it in your hand.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(small);
	set_wc(3,100);
	set_large_wc(4,100);
	set_property("enchantment",10);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^The room shudders for a second then it stops...  or was that just your mind?%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^Visions of driders and dark priestesses fill your mind%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^BLACK%^You duck instinctively as arrows come at you from nowhere... and then you look stupid when you realize it was only a vision%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^You hear the screams of driders as they die painfully%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes glaze over as her "+query_short()+" cuts deep into "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLACK%^"+targ->QCN+" screams silently as "+query_short()+" cuts deep wounds in their body%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^Visions of the underdark fill your thoughts as the "+query_short()+" cuts your body deeply%^RESET%^");
		targ->set_paralyzed(roll_dice(3,4)+-1);
return 0;	}
}
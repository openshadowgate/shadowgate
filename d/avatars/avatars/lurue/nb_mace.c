#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("mace");
	set_id(({ "mace" }));
	set_short("%^GREEN%^a g%^BOLD%^re%^RESET%^%^GREEN%^en%^BOLD%^is%^RESET%^%^GREEN%^h hued mace%^RESET%^");
	set_obvious_short("%^GREEN%^a g%^BOLD%^re%^RESET%^%^GREEN%^en%^BOLD%^is%^RESET%^%^GREEN%^h hued mace%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This g%^BOLD%^re%^RESET%^%^GREEN%^en%^BOLD%^is%^RESET%^%^GREEN%^h hued mace seems to glow with an inner light.  The head of the mace seems almost alien in shape, resembling some sort of large eyed bug.  Though made from what appears to be wood, the glow suggests something else might have gone in to making this mace.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(50);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^A brilliant %^GREEN%^green light%^WHITE%^ surges from the head of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^staggering "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^A brilliant %^GREEN%^green light%^WHITE%^ surges from the head of this "+query_short()+" %^BOLD%^%^WHITE%^staggering "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^A brilliant %^GREEN%^green light%^WHITE%^ surges from the head of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^staggering you!%^RESET%^");
		return roll_dice(5,0)+0;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("claws");
	set_id(({ "claws of malar", "claws", "claw" }));
	set_short("%^RESET%^%^RED%^Claws of %^ORANGE%^Malar%^RESET%^");
	set_obvious_short("A metal knuckle");
	set_long(
@AVATAR
%^ORANGE%^These metal knuckles have been studded with rows of six inch long sharp jagged edges along the top, much like a claw.  There are three claws in all.  The claws rest on what looks like a single brass knuckle.  The claws are wrapped with a snow white horse's hide, for comfort perhaps.  The claws are stained with blood and bear images of crude fierce beasts carved into the metal.

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_lore(
@AVATAR
The Claws of Malar may only be used by follower of the Lord of Hunt.  There have been plenty of stories about people who have tried to wield these weapons in combat and soon after being ripped apart by wild dogs and animals.  Be warned adventures, lest the same happens to you.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,4);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^ORANGE%^You feel your pulse quicken as you slip on the claws.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RED%^Your pulse returns to a dull mudane beat, as the thrill of the hunt leaves you");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 320){
	tell_room(environment(query_wielded()),"%^ORANGE%^"+ETO->query_cap_name()+" tears into "+targ->query_cap_name()+" with a savage blow.",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^You give "+targ->query_cap_name()+" a savage blow, tearing into them with the claws");
	tell_object(targ,"%^ORANGE%^OUCH! "+ETO->query_cap_name()+" tears into you with a savage blow, you can feel their metal claws sink into your flesh");
		return roll_dice(2,6)+2;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("chakram");
	set_id(({ "disk", "chakram", "night" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^Disk of %^RESET%^%^MAGENTA%^Night");
	set_obvious_short("circular piece of darkness");
	set_long(
@AVATAR
A circular section of pure darkness has been torn off.  The outter edge of the weapon give a violet glow

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
If you have this, Shar is going to be pissed

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("chakram");
	set_size(1);
	set_wc(700,4);
	set_large_wc(700,4);
	set_property("enchantment",30);
	set_ac(500);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Shar tears off a section of darkness and grasps it in her hand",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You tear off a section of darkness and grasp it");
	ETO->add_attack_bonus(50);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Shar releases the disk and plunges the area into a darkness",ETO);
	tell_object(ETO,"You release the disk and allow a darkness to fall upon the room");
	ETO->add_attack_bonus(-50);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^MAGENTA%^Shar channels her wrath at "+targ->query_cap_name()+"",({ETO,targ}));
	tell_object(ETO,"Shar channels her wrath at "+targ->query_cap_name()+"");
	tell_object(targ,"%^MAGENTA%^Shar channels her wrath at you!");
		return roll_dice(50,6)+40;	}
}
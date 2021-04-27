#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("thunderbolt");
	set_id(({ "spear" }));
	set_short("%^BOLD%^%^WHITE%^Th%^BOLD%^%^YELLOW%^under%^BOLD%^%^WHITE%^bolt%^RESET%^");
	set_obvious_short("A medium spear");
	set_long(
@AVATAR
This spear is is made out of a sturdy wood and has a %^BOLD%^%^YELLOW%^lightning bolt%^RESET%^ etched on the side, along it's entire length. Every so often an arc of %^BOLD%^%^CYAN%^lightning %^RESET%^jumps along the spear shaft.

AVATAR
	);
	set_weight(9);
	set_value(10000);
	set_lore(
@AVATAR
This is granted to Talos followers for their dedication.

AVATAR
	);
	set_type("piercing");
	set_prof_type("chaos spear");
	set_size(2);
	set_wc(2,6);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^As you grip the spear a shot of electricity %^BOLD%^%^RED%^shocks %^BOLD%^%^YELLOW%^you!");
	ETO->do_damage("torso",random(1d6));
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+ETO->query_cap_name()+"'s spear %^BOLD%^%^YELLOW%^glows %^RESET%^brightly and an arc of electricty %^BOLD%^%^RED%^bu%^BOLD%^%^YELLOW%^rs%^BOLD%^%^RED%^ts%^RESET%^ into "+targ->query_cap_name()+"!",({ETO,targ}));
	tell_object(ETO,"The spear %^BOLD%^%^YELLOW%^glows %^RESET%^brightly and an arc of electricty %^BOLD%^%^RED%^bu%^BOLD%^%^YELLOW%^rs%^BOLD%^%^RED%^ts%^RESET%^ into "+targ->query_cap_name()+"!");
	tell_object(targ,""+ETO->query_cap_name()+"'s spear %^BOLD%^%^YELLOW%^glows %^RESET%^brightly and an arc of electricty %^BOLD%^%^RED%^bu%^BOLD%^%^YELLOW%^rs%^BOLD%^%^RED%^ts%^RESET%^ into you!");
		return roll_dice(2,6)+-1;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("firelance");
	set_id(({ "lance" }));
	set_short("%^RESET%^%^RED%^L%^BOLD%^%^RED%^a%^BOLD%^%^BLUE%^n%^RESET%^%^RED%^c%^BOLD%^%^RED%^e %^BOLD%^%^BLUE%^o%^RESET%^%^RED%^f %^BOLD%^%^BLUE%^t%^RESET%^%^RED%^h%^BOLD%^%^%^RED%^e %^BOLD%^%^BLUE%^F%^RESET%^%^RED%^l%^BOLD%^%^BLUE%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^RESET%^ ");
	set_obvious_short("A rune encrusted lance");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This heavy lance is covered with spiraling %^RESET%^%^RED%^red %^BOLD%^%^YELLOW%^runes %^BOLD%^%^RED%^that seems to surge with magical energy. The grip of the lance is well crafted to add comfort to the wielder. Across the center of the lance is a %^RESET%^%^RED%^holy symbol of Kossuth %BOLD%^%^RED%^which seems to glow constantly. The tip of the lance has small grooves on the tip which seem to twist and are barbed for the most impact when used in combat.

AVATAR
	);
	set_weight(20);
	set_value(2000);
	set_lore(
@AVATAR
Created by a wizard named Pakanoran, it was gifted to the Anti-paladin Reeve, follower of Kossuth as a gift by Lord Tarek of Asgard. It has been passed on throughout the temple of Kossuth to those deemed worthy to carry it.

AVATAR
	);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(2);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^Flames dance around the length of the lance.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Flames leap forth from the lance, %^BOLD%^%^YELLOW%^surrounding %^BOLD%^%^RED%^ it completely. You feel the warmth of Kossuth as you wield the weapon.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^The flames disappear, flowing back into the lance.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The flames die down, you feel the coolness re-enter your body.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^The lance glows brightly as a ball of fire shoots forth at "+targ->query_cap_name()+".",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The lance grows hot as it propels a ball of flame at its target!");
	tell_object(targ,"%^BOLD%^%^RED%^You see the energy around the lance grow bright as a ball of fire streaks towards you, slamming into you!");
		return roll_dice(5,6)+0;	}
}
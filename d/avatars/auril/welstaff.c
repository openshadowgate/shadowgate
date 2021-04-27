#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("welstaff");
	set_id(({ "staff" }));
	set_short("%^BOLD%^%^WHITE%^Staff of %^BOLD%^%^YELLOW%^P%^RESET%^o%^BOLD%^%^WHITE%^w%^BOLD%^%^YELLOW%^e%^RESET%^r");
	set_obvious_short("An ornate staff");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This staff is ornately crafted and has runes covering the entire length of it. It is about five feet in length and has a sphere on the top that cackles with magical energy constantly, sending inch long bolts of%^BOLD%^%^CYAN%^lightning %^BOLD%^%^YELLOW%^around it in all directions. The power felt in this weapon is immense.

AVATAR
	);
	set_weight(10);
	set_value(15000);
	set_lore(
@AVATAR
This staff was crafted by the great wizard Welkanar. Mage and protector to the King of Antioch he has used it for many years to protect the King and the kings that were before him.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(1);
	set_wc(2,6);
	set_large_wc(2,4);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^As "+ETO->query_cap_name()+" wields the weapon, energy cackles around him.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Power flows through you as you wield the weapon.");
	ETO->add_attack_bonus(5);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^As "+ETO->query_cap_name()+" unwields the weapon, the energy ceases its magical cackle.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Power leaves you as you unwield the weapon.");
	ETO->add_attack_bonus(-5);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^Energy builds up around the staff and the air begins to thicken with magical energy. "+ETO->query_cap_name()+" raises his hands to the air and screams %^BOLD%^%^RED%^Aslak fornan Kelkron! %^BOLD%^%^CYAN%^and %^BOLD%^%^YELLOW%^lightning bolts %^BOLD%^%^CYAN%^rain down upon "+targ->query_cap_name()+".",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Magical energy strikes your target!");
	tell_object(targ,"%^BOLD%^%^CYAN%^Energy builds up around the staff and the air begins to thicken with magical energy. "+ETO->query_cap_name()+" raises his hands to the air and screams %^BOLD%^%^RED%^Aslak fornan Kelkron! %^BOLD%^%^CYAN%^and %^BOLD%^%^YELLOW%^lightning bolts %^BOLD%^%^CYAN%^rain down upon you!");
		return roll_dice(8,10)+0;	}
}
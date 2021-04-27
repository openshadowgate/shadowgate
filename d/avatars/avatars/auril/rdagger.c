#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("death dagger");
	set_id(({ "dagger" }));
set_short("%^BOLD%^%^BLACK%^Ste%^BOLD%^%^CYAN%^a%^BOLD%^%^BLACK%^lthwh%^BOLD%^%^CYAN%^i%^BOLD%^%^BLACK%^sper dagger%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A long dagger%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This long black dagger is made out of a darkened steel. It is exquisitely simple in its craftsmanship and has no unusually tell mark features save one, the %^BOLD%^%^CYAN%^quartz %^BOLD%^%^BLACK%^pommel. Inside the small piece of %^BOLD%^%^CYAN%^quartz %^BOLD%^%^BLACK%^whispy %^BOLD%^%^WHITE%^smoke%^BOLD%^%^BLACK%^ moves about slowly.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10000);
	set_lore(
@AVATAR
This dagger was crafted fourty years ago by an unknown craftsman. The dagger was for the leader of the Asgard Assassin Guild, and word was out it could suck the soul out of its victims.

AVATAR
	);
	set_property("lore difficulty",30);
        set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",4);
	set_ac(2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Dark whispy mist flows from "+ETOQCN+"'s dagger, wrapping "+ETOQCN+"'s arms and torso in an obscuring mist.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Dark whispy mist flows from the %^BOLD%^%^CYAN%^quartz%^BOLD%^%^BLACK%^ pommel, wrapping your arms and torso in an obscuring mist.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The mist flows back into the dagger as "+ETOQCN+" unwields the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The mist flows back into the dagger as you unwield the weapon.");
	return 1;
}
int hit_func(object targ){
       if(random(1000) < 100){
        tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETO->QCN+" sees an opening in "+targ->QCN+"'s defenses and steps in deftly, sliding "+ETO->QP+" dagger through "+targ->QCN+"'s defenses. As the dagger is thrust in you see "+targ->QCN+"'s eyes become lifeless and his %^BOLD%^%^WHITE%^soul %^BOLD%^%^BLACK%^leave "+targ->QCN+"'s eyes and enters the pommel of "+ETO->QCN+"'s dagger.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You see an opening in "+targ->QCN+"'s defenses and step in deftly, sliding your dagger through his defenses. As the dagger is thrusted in, you feel a %^BOLD%^%^CYAN%^hum %^BOLD%^%^BLACK%^as "+targ->QCN+"'s eyes become lifeless and his %^BOLD%^%^WHITE%^soul %^BOLD%^%^BLACK%^leaves "+targ->QCN+"'s eyes and enters the pommel.");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" grins slightly and plunges their %^BOLD%^%^CYAN%^quartz %^BOLD%^%^BLACK%^dagger deep into your side. You feel instantly %^BOLD%^%^BLUE%^cold %^BOLD%^%^BLACK%^and you feel as if your %^BOLD%^%^WHITE%^soul %^BOLD%^%^BLACK%^is being ripped from you!");
                return roll_dice(5,10)+0;
  }
}

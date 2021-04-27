#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dark iron mace");
	set_id(({ "mace" }));
	set_short("%^BOLD%^%^BLACK%^Corrupt Mace of %^RED%^Dis%^RESET%^%^RED%^rup%^MAGENTA%^ti%^BOLD%^%^BLACK%^on%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^dark iron mace%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a mace forged out of almost solid dark iron.  The shaft is thick and dense, and highly decorated in a chaotic %^BLUE%^sea-like%^BLACK%^ motif.  The grip is wound tightly in %^RESET%^%^ORANGE%^thick leather%^BOLD%^%^BLACK%^, causing a slip of the weapon in hand a rare occurrence.  The striking head of the mace is large, about half again the size of a large grapefruit.  It is dense and solid, feeling heavy in hand.  It is polished perfectly smooth and round, such that you can make out your reflection vaguely on the dark surface.  The whole head hums quietly.%^RESET%^

AVATAR
	);
	set_weight(11);
	set_value(3000);
	set_lore(
@AVATAR
A Mace of Disruption was a common weapon in the battle against the undead. 
Few remain today.  The maces were most commonly crafted by priests of
lawful faiths, and they are said to be blessed against the living dead. 
Its name comes from the aura surrounding the striking head, which has a
vibrating aura used to shatter nonliving material.  The shaft of each mace
was usually personalized for its former owner or church.


AVATAR
	);
	set_property("lore difficulty",15);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(2,4);
	set_large_wc(1,7);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The mace h%^RESET%^%^RED%^u%^BOLD%^m%^BLACK%^s as "+ETOQCN+" wields the heavy weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The mace h%^RESET%^%^RED%^u%^BOLD%^m%^BLACK%^s in your hand as you wield it.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The mace ceases its humming as "+ETOQCN+" unwields it.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You no longer hear the mace humming as you unwield it.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^As "+ETOQCN+" swings their mace, "+targ->QCN+" is struck by a wave of %^BOLD%^%^RED%^dis%^RESET%^%^RED%^rup%^MAGENTA%^ti%^BOLD%^%^BLACK%^on!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you swing your mace your enemy is struck by a wave of %^BOLD%^%^RED%^dis%^RESET%^%^RED%^rup%^MAGENTA%^ti%^BOLD%^%^BLACK%^on!");
	tell_object(targ,"%^BOLD%^%^BLACK%^As "+ETOQCN+" swings their mace, you are struck by a wave of %^BOLD%^%^RED%^dis%^RESET%^%^RED%^rup%^MAGENTA%^ti%^BOLD%^%^BLACK%^on!");
		return roll_dice(1,10)+0;	}

}

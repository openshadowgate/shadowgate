#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("psiblade");
	set_id(({ "blade", "sword", "shortsword", "short sword", "psiblade" }));
	set_short("%^BOLD%^%^MAGENTA%^Ps%^RESET%^%^MAGENTA%^i%^BOLD%^bl%^RESET%^%^MAGENTA%^a%^BOLD%^d%^RESET%^%^MAGENTA%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^cr%^RESET%^%^MAGENTA%^y%^BOLD%^st%^RESET%^%^MAGENTA%^a%^BOLD%^l %^RESET%^%^MAGENTA%^bladed %^BOLD%^%^BLACK%^shortsword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^At first, the blade in your hand looks primitive but on closer inspection you find it is dangerous and remarkable.  The blade appears to be fashioned out a single flawless shard of %^BOLD%^am%^RESET%^%^MAGENTA%^e%^BOLD%^thyst%^RESET%^%^MAGENTA%^, chipped away slowly and meticulously by flaking until razor sharp, not unlike an arrowhead.  The end of the shard has been reinforced with an unseen metal and wrapped tightly with %^BOLD%^%^BLACK%^black leather%^RESET%^%^MAGENTA%^ that offers a stable grip.  When you look deeply into the crystal blade, you see faintly pu%^BOLD%^lsa%^CYAN%^t%^MAGENTA%^in%^RESET%^%^MAGENTA%^g veins within.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(2000);
	set_lore(
@AVATAR
Psiweapons are those carefully crafted within psionic enclaves to offer personal protection to the masters of the mind.  Rumor has it that the art was perfected by mind flayers of the Underdark but they have not been confirmed.  Only the purest crystals can be made into such items.  They help protect the minds of psions in battle from other powers and spells.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("short blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,4);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" looks more confident as they wield the blade.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel a barrier of protection form in your mind.");
	ETO->add_attack_bonus(2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" seems somehow vulnerable as they unwield the blade.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel somehow vulnerable as you unwield the blade.");
	ETO->add_attack_bonus(-2);
	return 1;
}


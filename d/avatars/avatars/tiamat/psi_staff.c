#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Psistaff");
	set_id(({ "staff", "psistaff", "psi staff" }));
	set_short("%^BOLD%^%^MAGENTA%^Ps%^RESET%^%^MAGENTA%^i%^BOLD%^st%^RESET%^%^MAGENTA%^a%^BOLD%^f%^RESET%^%^MAGENTA%^f%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^cr%^RESET%^%^MAGENTA%^y%^BOLD%^st%^RESET%^%^MAGENTA%^a%^BOLD%^l %^RESET%^%^MAGENTA%^topped %^BOLD%^%^BLACK%^staff%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This is a sturdy %^BOLD%^%^BLACK%^ironwood%^RESET%^%^MAGENTA%^ staff topped with a short blade made of crystal.  The blade appears to be fashioned out a single flawless shard of %^BOLD%^am%^RESET%^%^MAGENTA%^e%^BOLD%^thyst%^RESET%^%^MAGENTA%^, chipped away slowly and meticulously by flaking until razor sharp, not unlike an arrowhead.  The end of the shard is wrapped tightly with %^BOLD%^%^BLACK%^black leather%^RESET%^%^MAGENTA%^ that secures it to the %^BOLD%^%^BLACK%^staff%^RESET%^%^MAGENTA%^.  When you look deeply into the crystal blade, you see faintly pu%^BOLD%^lsa%^CYAN%^t%^MAGENTA%^in%^RESET%^%^MAGENTA%^g veins within.%^RESET%^

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
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(2,4);
	set_large_wc(2,5);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" looks more confident as they wield the staff.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel a barrier of protection form in your mind.");
	ETO->add_attack_bonus(3);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" seems somehow vulnerable as they unwield the staff.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel somehow vulnerable as you unwield the staff.");
	ETO->add_attack_bonus(-3);
	return 1;
}


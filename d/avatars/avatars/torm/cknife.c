#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Crooked Knife");
	set_id(({ "knife", "crooked knife", "hooked knife" }));
	set_short("%^BOLD%^%^BLACK%^Cro%^RESET%^%^ORANGE%^oked %^BOLD%^%^WHITE%^Knife%^RESET%^");
	set_obvious_short("an odd knife");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This small knife has a slender pointed blade that curves back on itself to form a hook.  The blade is very sharp and looks to be in excellent condition.  %^RESET%^%^ORANGE%^It is bound securely to a stocky wo%^RED%^o%^ORANGE%^den handle with a length of %^BOLD%^%^BLACK%^thin, twisted black cord.

AVATAR
	);
	set_weight(2);
	set_value(850);
	set_lore(
@AVATAR
%^RED%^Odd looking knives of this sort can be found all over the realms, usually in a carpenter's workshop.  The sharp, curved blade is used most commonly to hollow out bowls and dishes.

AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",1);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The cord allows%^RESET%^%^ORANGE%^ a firm grip on the handle%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 210){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^A chunk of "+targ->QCN+"'s flesh flies through the air!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^Your knife takes a chunk out of "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"'s crooked dagger gouges out your flesh!%^RESET%^");
		return roll_dice(1,3)+1;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("oldsword");
	set_id(({ "longsword", "sword", "long sword" }));
	set_short("%^RESET%^O%^BOLD%^%^BLACK%^l%^RESET%^'Fa%^ORANGE%^i%^RESET%^th%^BOLD%^%^BLACK%^f%^RESET%^ul");
	set_obvious_short("%^RESET%^ba%^ORANGE%^t%^RESET%^te%^BOLD%^%^BLACK%^r%^RESET%^ed %^ORANGE%^sword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This old battered sword has seen better days. As nicked and beat up as the sword is, the edge holds true. It is a simple sword without any frill, a down to earth weapon for a down to earth bearer. A simple %^BLACK%^%^BOLD%^iron%^RESET%^%^ORANGE%^ crossguard and a %^RED%^leather%^ORANGE%^ wrapped handle keep the hand of the wielder intact.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(100);
	set_lore(
@AVATAR
Swords as common as these are common across the realm, though this one, battered as it is, somehow manages to keep it's sharp edge. It is siad that swrds as old as these somehoe achive a type of living knowlegde and awareness of thier surroundings after surviving this long in the hands of an adventurer.

AVATAR
	);
	set_property("lore difficulty",4);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" takes a firm grip of the sword%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You take hold of the sword and are ready for a %^RED%^fight%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" flexes thier fingers as they release the blade%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You release the hilt and long for it's touch%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^A flicker of l%^WHITE%^i%^CYAN%^ght is seen as "+ETOQCN+" strikes "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^Runes fli%^BLACK%^c%^CYAN%^ker along the edge as you strike "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^CYAN%^%^BOLD%^Energy lashes from the blade into you!%^RESET%^");
		return roll_dice(1,10)+0;	}
}
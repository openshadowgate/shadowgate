#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^T%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^rant's Sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the%^RESET%^");
	set_id(({ "scythe", "Scythe", "Tyrant", "tyrant" }));
	set_short("%^BOLD%^%^BLACK%^T%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^rant's Sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the%^RESET%^");
	set_obvious_short("Black scythe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a huge sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the. The shaft of the weapon is made of pure %^RESET%^%^BLUE%^darkness %^BOLD%^%^BLACK%^with %^BOLD%^%^GREEN%^green runes %^BOLD%^%^BLACK%^littering it, the giant blade is pure darkness aswell, though with no runes on it. An %^BOLD%^%^CYAN%^aura %^BOLD%^%^BLACK%^of dark power radiates out from this weapon, the %^BOLD%^%^CYAN%^aura %^BOLD%^%^BLACK%^is so great that you think a mortal might die from just being near to it. This giant weapon looks to be for a creature at least ten feet tall.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("bane scythe");
	set_size(2);
	set_wc(10000,10000);
	set_large_wc(10000,10000);
	set_property("enchantment",30);
	set_ac(5000);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" radiates a dark and powerful aura.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^A dark power envolopes you.%^RESET%^");
	ETO->add_attack_bonus(10000);
	ETO->add_damage_bonus(10000);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The dark aura leaves "+ETOQCN+" as he unwields the scythe.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You feel weak and unimportant now.%^RESET%^");
	ETO->add_attack_bonus(-10000);
	ETO->add_damage_bonus(-10000);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^As %^RESET%^%^BLUE%^"+ETOQCN+" %^BOLD%^%^BLACK%^slashes %^BOLD%^%^RED%^"+targ->QCN+" %^BOLD%^%^BLACK%^with his sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the it fl%^BOLD%^%^GREEN%^i%^BOLD%^%^BLACK%^ckers briefly and seems to cleave %^BOLD%^%^RED%^"+targ->QCN+"'s %^BOLD%^%^GREEN%^soul!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you slash %^BOLD%^%^RED%^"+targ->QCN+" %^BOLD%^%^BLACK%^the sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the fl%^BOLD%^%^GREEN%^i%^BOLD%^%^BLACK%^ckers and seems to cleave their %^BOLD%^%^GREEN%^soul!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^As %^RESET%^%^BLUE%^"+ETOQCN+" %^BOLD%^%^BLACK%^slashes into you with his sc%^BOLD%^%^GREEN%^y%^BOLD%^%^BLACK%^the it fl%^BOLD%^%^GREEN%^i%^BOLD%^%^BLACK%^ckers and you feel your %^BOLD%^%^GREEN%^soul %^BOLD%^%^BLACK%^get %^BOLD%^%^RED%^torn %^BOLD%^%^BLACK%^away!");
		targ->set_paralyzed(roll_dice(5,5)+5);
return 0;	}
}
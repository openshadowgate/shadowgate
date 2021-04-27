#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Dim Blue Antioch sword");
	set_id(({ "sword" }));
	set_short("%^CYAN%^Ancient sword of the warlord%^RESET%^");
	set_obvious_short("%^CYAN%^a dim blue sword%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This dim blue glowing sword, is about 2 1/2 feet long, and is made out of a light unknown material.  The legends tell about the sword giving its wielder courage and strength%^RESET%^.

AVATAR
	);
	set_weight(10);
	set_value(5000);
	set_lore(
@AVATAR
The sword of the warlord is a ancient sword that is rumored to give its wearer courage and strength.
AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,5);
	set_large_wc(2,6);
	set_property("enchantment",2);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^CYAN%^As "+ETO->query_cap_name()+" wields the dim blue sword, it starts to glow softly%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^As you wield the sword, you feel your strength and courage rise%^RESET%^.");
	ETO->add_stat_bonus("strength",1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^CYAN%^As "+ETO->query_cap_name()+" unwields the sword, it stops glowing and returns to its dim blue state%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^The sword's glow slowly dims, and you feel its powers returning to the sword%^RESET%^");
        if ((TP == ETO) && (query_verb() != "quit")) {
	ETO->add_stat_bonus("strength",-1);
        }
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^CYAN%^"+ETO->query_cap_name()+" swings his sword and hits "+targ->query_cap_name()+" with alot of power%^RESET%^.",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^Your sword hits "+targ->query_cap_name()+" with extra power and causes severe damage.");
	tell_object(targ,"%^CYAN%^"+ETO->query_cap_name()+" swings his sword at you, and causes severe damage%^RESET%^.");
		return roll_dice(3,4)+-1;	}
}

#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^RED%^Big %^BOLD%^%^BLUE%^Fn %^RESET%^%^RED%^Axe%^RESET%^");
	set_id(({ "axe", "Axe", "baneaxe", "Baneaxe" }));
	set_short("%^BOLD%^%^RED%^Big %^BOLD%^%^BLUE%^Fn %^RESET%^%^RED%^Axe%^RESET%^");
	set_obvious_short("A huge freaken axe");
	set_long(
@AVATAR
%^RESET%^%^BLUE%^This is one huge axe. The shaft on the axe is around twelve feet long with a foot long spike jutting out the top. Two half-moon blades make up the axe head, each blade is around three feet. The whole axe is made of some %^BOLD%^%^BLACK%^strange black material%^RESET%^%^BLUE%^, seemingly metal but with almost no weight at all. Small %^BOLD%^%^GREEN%^green veins %^RESET%^%^BLUE%^run throughout the axe and seem to pulse at times, all the veins seem to move, never staying in the same place for long.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5000);
	set_lore(
@AVATAR
0

AVATAR
	);
	set_property("lore difficulty",1000);
	set_type("slashing");
	set_prof_type("giant axe");
	set_size(1);
	set_wc(18,6);
	set_large_wc(18,6);
	set_property("enchantment",10);
	set_ac(10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(10);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-10);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 334){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"");
		return roll_dice(10,10)+10;	}
}
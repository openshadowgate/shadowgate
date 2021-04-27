#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger", "black dagger", "black dagger +1", "death dagger" }));
	set_short("%^RED%^Death Dagger +1%^RESET%^");
	set_obvious_short("%^RED%^a blood-covered dagger%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This dagger is soaked in %^RESET%^%^RED%^oozing blood%^BOLD%^%^BLACK%^, perhaps fresh from its most recent victim. The blade has a very jagged edge, allowing one to %^RESET%^%^RED%^pierce%^BOLD%^%^BLACK%^ through any type of armor with virtual ease.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^This dagger was handed down by the goblin king to his assassin, Harthugg. It is told amongst the goblinkin that the one that Harthugg presents with this dagger will be next in line to take his place. This dagger holds great prestige among the goblinkin, especially those desiring power.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set("dexbonus",1);
	set_type("piercing");
	set_prof_type("blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" %^RESET%^%^RED%^grips their "+query_short()+" %^RESET%^%^RED%^and begins to drool!%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You begin to think about %^BOLD%^%^RED%^blood %^RESET%^%^RED%^as you grip the "+query_short()+" %^RESET%^%^RED%^tightly.%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" %^RESET%^%^RED%^stops drooling as they unwield their "+query_short()+" %^RESET%^%^RED%^slowly.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^Your heartbeat slows down as you ungrip the "+query_short()+" %^RESET%^%^RED%^almost unwillingly.%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^RED%^The "+query_short()+" %^RESET%^%^RED%^pierces the flesh of "+targ->QCN+" %^RESET%^%^RED%^which makes "+targ->QCN+" %^RESET%^%^RED%^bleed uncontrollably!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^Your "+query_short()+" %^RESET%^%^RED%^pierces the flesh of "+targ->QCN+" %^RESET%^%^RED%^with its jagged edge making them bleed uncontrollably!%^RESET%^");
	tell_object(targ,"%^RED%^You feel your arteries caving in as "+ETOQCN+" %^RESET%^%^RED%^slices you with their "+query_short()+" %^RESET%^%^RED%^quickly!%^RESET%^");
		targ->set_paralyzed(roll_dice(20,0)+0);
return 0;	}

}

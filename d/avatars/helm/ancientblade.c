#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Ancient Blade");
	set_id(({ "sword", "blade", "ancient blade", "longsword", "long sword" }));
	set_short("%^BOLD%^%^BLACK%^Ancient Blade%^RESET%^");
	set_obvious_short("old sword");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The blade is razorsharp and roughly three feet seven inches long. It is wrought in a strong and %^RESET%^silvery alloy%^BOLD%^%^BLACK%^ that leads one to believe that elves were once involved in it's creation. The crossguard consists of two wings that protudes from the hilt. In the centre where they meet, a %^RESET%^%^RED%^ruby%^BOLD%^%^BLACK%^ is set. The world burns red when looked upon through the gemstone. Straps of darkened %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLACK%^ has been carefully wound around the hilt, ensuring the wielder a comfortable and durable grip even in the heat of the fiercest battles. The pommel itself resembles the foot of a bird of prey. A single %^RESET%^%^GREEN%^emerald%^BOLD%^%^BLACK%^ is held in place by the gripping %^RESET%^talons%^BOLD%^%^BLACK%^.

AVATAR
	);
	set_weight(20);
	set_value(0);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"As "+ETO->query_cap_name()+" grabs the hilt of the "+query_short()+" the pommeljewel flashes pale green for just a second.",ETO);
	tell_object(ETO,"As you grab the hilt of the "+query_short()+" the pommeljewel flashes pale green for just a second.");
	ETO->add_attack_bonus(6);
	ETO->add_damage_bonus(6);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"As "+ETO->query_cap_name()+" unwields the "+query_short()+" the pommeljewel flashes green for an instant and then fades.",ETO);
	tell_object(ETO,"The pommeljewel flashes green for an instant and then fades.");
	ETO->add_attack_bonus(-6);
	ETO->add_damage_bonus(-6);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"The %^RESET%^%^RED%^ruby%^RESET%^ on "+ETO->query_cap_name()+"'s sword flashes once and the blade seems to glow %^RED%^red%^RESET%^ for a short while.",({ETO,targ}));
	tell_object(ETO,"The %^RESET%^%^RED%^ruby%^RESET%^ flashes once and the blade seems to glow %^RED%^red%^RESET%^ for a short while.");
	tell_object(targ,"The blade of "+ETO->query_cap_name()+"'s sword glows red for a short while as it slips past your defences.");
		return roll_dice(3,6)+0;	}
}
#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
	::create();
	set_name("%^BOLD%^%^CYAN%^W%^RESET%^%^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g%^WHITE%^ C%^BLACK%^h%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^RESET%^");
	set_id(({ "chains", "chainmail", "chain mail", "wailing chains" }));
	set_short("%^BOLD%^%^CYAN%^W%^RESET%^%^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g%^WHITE%^ C%^BLACK%^h%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^W%^RESET%^%^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g%^WHITE%^ C%^BLACK%^h%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^These c%^BLACK%^h%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^WHITE%^ were forged from pure %^RESET%^%^MAGENTA%^misery%^BOLD%^%^WHITE%^ and %^RED%^sin%^WHITE%^. They %^CYAN%^w%^RESET%^%^"
	"CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^ incessantly, driving the bearer to grief for crimes committed in life. To a mortal they might provide some material protection from attack -- at the"
	" price of listening to the howling.%^RESET%^ 
"
	);
	set_value(0);
	set_lore("These are the chains given by Kelemvor to the those who have done evil and must wander the lands in punnishment for their crimes. Thus the pennitent haunted souls may still ascend to the Celestial pla"
	"nes on the completion of their assigned burden. The less fortunate who do not repend their deeds descend to the Abyss to await their eternal torment.
"
	);
    set_property("lore difficulty",20);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" staggers under the weight of the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g %^BLACK%^chains!!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The chains you bear feel so %^BLACK%^heavy!!%^RESET%^");
	ETO->set_property("magic resistance",10);
	ETO->add_skill_bonus("perception",-2);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" looks like a great burden has been lifted.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel like a great burden has been lifted from your shoulders.%^RESET%^");
	ETO->set_property("magic resistance",-10);
	ETO->add_skill_bonus("perception",2);
	return 1;
}


void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(random(500) > 495) 
	 {
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^WHITE%^The chains you wear wail their %^YELLOW%^agony!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^The chains "+ETOQCN+" wears wail their %^YELLOW%^agony!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^WHITE%^The %^CYAN%^wailing%^WHITE%^ chains %^RED%^choke%^WHITE%^ the life out of you!!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^"+ETOQCN+" gasps as the %^CYAN%^wailing%^WHITE%^ chains %^RED%^start constricting%^WHITE%^!!%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^WHITE%^The chains you bear feel so %^BLACK%^heavy!!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^"+ETOQCN+" staggers under the weight of the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^BOLD%^g %^BLACK%^chains!!%^RESET%^", ({ETO}));
				break;
		}
	}
}
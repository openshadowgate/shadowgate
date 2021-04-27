#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("%^RESET%^%^MAGENTA%^po%^RED%^i%^MAGENTA%^son%^RED%^o%^MAGENTA%^us %^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^CYAN%^c%^GREEN%^l%^CYAN%^a%^GREEN%^w%^CYAN%^s%^RESET%^");
	set_id(({ "claws", "claw", "zombie claws", "poisonous zombie claws", "poisonous claws" }));
	set_short("%^RESET%^%^MAGENTA%^po%^RED%^i%^MAGENTA%^son%^RED%^o%^MAGENTA%^us %^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^CYAN%^c%^GREEN%^l%^CYAN%^a%^GREEN%^w%^CYAN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^po%^RED%^i%^MAGENTA%^son%^RED%^o%^MAGENTA%^us %^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^CYAN%^c%^GREEN%^l%^CYAN%^a%^GREEN%^w%^CYAN%^s%^RESET%^");
	set_long("%^RESET%^%^CYAN%^These claws look to be from a human hand where the fingernails have transformed into horrible, chitinous %^BOLD%^%^BLACK%^black claws%^RESET%^%^CYAN%^ that ooze with a pestilential ic"
	"hor. It is likely that they are quite %^MAGENTA%^poisonous%^CYAN%^, and filled with negative plane energy of the undead. %^RESET%^
"
	);
	set_value(0);
	set_lore("Ethius was once a devout follower of Cyric, but he decided to leave when Cyrics dogma changed. Alzar the high priest hunted Ethius down and trapped his soul in a bottle. Cyric leveled a curse on Ethiu"
	"s that his corpse should remain a zombie and forever try to reclaim his soul. These are the claws that grew out of Ethius hands on that fateful day.
"
	);
    set_property("lore difficulty",10);
	set_heart_beat(1);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-1);
	ETO->add_attack_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+" slashes viciously with "+query_short()+"%^YELLOW%^ leaving %^RESET%^%^MAGENTA%^hideous %^BOLD%^%^RED%^p%^RESET%^%^RED%^o%^BOLD%^i%^RESET%^%^RED%^s%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^e%^RESET%^%^RED%^d%^MAGENTA%^ wounds%^YELLOW%^ on "+targ->QCN+".%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^Your "+query_short()+"%^YELLOW%^ leave %^RESET%^%^MAGENTA%^hideous %^BOLD%^%^RED%^p%^RESET%^%^RED%^o%^BOLD%^i%^RESET%^%^RED%^s%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^e%^RESET%^%^RED%^d%^MAGENTA%^ wounds%^YELLOW%^ on "+targ->QCN+".%^RESET%^");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+" slashes viciously with "+query_short()+"%^YELLOW%^ leaving %^RESET%^%^MAGENTA%^hideous %^BOLD%^%^RED%^p%^RESET%^%^RED%^o%^BOLD%^i%^RESET%^%^RED%^s%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^e%^RESET%^%^RED%^d%^MAGENTA%^ wounds%^YELLOW%^ across your body.%^RESET%^");
		return roll_dice(10,6)+0;	}

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
	 if(random(1000) > 998) 
	 {
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^GREEN%^Vile %^RESET%^%^MAGENTA%^ichor%^BOLD%^%^GREEN%^ drips from "+query_short()+"%^BOLD%^%^GREEN%^ in the hands of "+ETOQCN+".%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^GREEN%^Vile %^RESET%^%^MAGENTA%^ichor%^BOLD%^%^GREEN%^ drips from "+query_short()+"%^BOLD%^%^GREEN%^ in the hands of "+ETOQCN+".%^RESET%^", ({ETO}));
				break;
		}
	}
}
#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create(){
	::create();
	set_name("rapier");
	set_id(({ "rapier", "drow rapier" }));
	set_short("%^BOLD%^%^BLACK%^Drow %^RESET%^%^MAGENTA%^d%^CYAN%^a%^MAGENTA%^r%^CYAN%^k%^MAGENTA%^s%^CYAN%^t%^MAGENTA%^e%^CYAN%^e%^MAGENTA%^l%^BOLD%^%^BLACK%^ rapier%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^d%^CYAN%^a%^MAGENTA%^r%^CYAN%^k%^MAGENTA%^s%^CYAN%^t%^MAGENTA%^e%^CYAN%^e%^MAGENTA%^l%^BOLD%^%^BLACK%^ rapier%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This is a long, slender shadowy blade made out of %^RESET%^%^MAGENTA%^d%^CYAN%^a%^MAGENTA%^r%^CYAN%^k%^MAGENTA%^s%^CYAN%^t%^MAGENTA%^e%^CYAN%^e%^MAGENTA%^l%^BOLD%^%^BLUE%^, or some oth"
	"er derivative composite. It is %^BLACK%^razor sharp%^BLUE%^, with a %^RED%^killing tip%^BLUE%^. It seems sharper than a normal steel blade and remarkably flexible. The hilt has an ornate guard that is"
	" embellished with a %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k w%^RESET%^e%^BOLD%^%^BLACK%^b%^BLUE%^ with a %^RED%^red female eye%^BOLD%^%^BLUE%^ in the center.%^RESET%"
	"^
"
	);
	set_value(1000);
	set_lore("%^BOLD%^%^BLUE%^This is a rapier forged in the Underdark for the %^BOLD%^%^BLACK%^A%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^n%^BOLD%^%^BLACK%^t%^RESET%^s%^BOLD%^%^BLUE%^ of %^RESET%^%^RED%^H%^RESET%^o%^BO"
	"LD%^%^BLACK%^u%^RESET%^%^RED%^s%^RESET%^e%^BOLD%^%^BLACK%^ T%^RESET%^e%^RED%^k%^BOLD%^%^BLACK%^e%^RESET%^n%^BOLD%^%^RED%^'%^BLACK%^g%^RESET%^h%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^m%^RESET%^!%^RESET%^ %^B"
	"OLD%^%^BLUE%^The blades are famously dangerous in one-on-one combat, made for vicious duels, back alley skirmishes, yet less helpful in outright field battles where larger blades and heavy armor outpe"
	"rforms them.%^RESET%^
"
	);
    set_property("lore difficulty",20);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The rapier feels comfortable in your hand, well balanced and extraordinarily light.%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	ETO->add_skill_bonus("stealth",2);
	ETO->add_skill_bonus("athletics",2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As the rapier leaves your hand you feel as if you have let go of a masterful blade.%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	ETO->add_skill_bonus("stealth",-2);
	ETO->add_skill_bonus("athletics",-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+"%^BOLD%^%^CYAN%^ lunges with "+query_short()+"%^BOLD%^%^CYAN%^ leaving a%^RED%^ vicious hole%^BOLD%^%^CYAN%^ in "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You lunge with your "+query_short()+"%^BOLD%^%^CYAN%^, putting a %^RED%^vicious hole%^CYAN%^ in "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ lunges, skewering you with the "+query_short()+"%^BOLD%^%^CYAN%^... You feel as if you can %^BLACK%^hardly breathe!!%^RESET%^");
		return roll_dice(1,20)+10;	}

}

#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^W%^BOLD%^a%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^%^CYAN%^ of the %^BOLD%^F%^RESET%^%^CYAN%^o%^BOLD%^u%^RESET%^%^CYAN%^r M%^BOLD%^o%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^RESET%^");
	set_id(({ "wand", "rod", "mace" }));
	set_short("%^RESET%^%^CYAN%^W%^BOLD%^a%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^%^CYAN%^ of the %^BOLD%^F%^RESET%^%^CYAN%^o%^BOLD%^u%^RESET%^%^CYAN%^r M%^BOLD%^o%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^i%^RESET%^%^CYAN%^m%^BOLD%^m%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^g W%^BOLD%^a%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a replica of the famous %^RESET%^%^CYAN%^W%^BOLD%^a%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^%^CYAN%^ of the %^BOLD%^F%^RESET%^%^CYAN%^o%^BOLD%^u%^RESET%^%^CYAN%^r M%^BOLD%^o%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^, the weapon of the Goddess %^CYAN%^Selune%^WHITE%^. It glows with a soft %^RESET%^%^CYAN%^s%^GREEN%^i%^CYAN%^l%^GREEN%^v%^CYAN%^e%^GREEN%^r%^CYAN%^y %^BLUE%^l%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^g%^BOLD%^h%^RESET%^%^BLUE%^t%^BOLD%^%^WHITE%^, piercing even the deepest %^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^ad%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^. A little over a foot and a half in length, it is made of what must be %^RESET%^%^GREEN%^m%^BOLD%^o%^RESET%^%^GREEN%^o%^BOLD%^n%^RESET%^%^ORANGE%^ r%^YELLOW%^o%^RESET%^%^ORANGE%^ck%^BOLD%^%^WHITE%^ and seems to move through the air without even the slightest resistance. It exudes the soft presence of the %^BOLD%^%^CYAN%^L%^RESET%^%^CYAN%^a%^BOLD%^dy%^BOLD%^%^WHITE%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^M%^RESET%^%^CYAN%^o%^BOLD%^o%^RESET%^%^CYAN%^n %^RESET%^be thy %^BOLD%^%^WHITE%^Guide%^RESET%^ in %^MAGENTA%^d%^BOLD%^%^BLACK%^a%^RESET%^MAGENTA%^rk%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^ess.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(10000);
	set_lore(
@AVATAR
%^RESET%^%^GREEN%^This wand was forged in honor of %^BOLD%^%^CYAN%^Selune's %^WHITE%^victory%^RESET%^%^GREEN%^ over %^BOLD%^%^BLACK%^Shar%^RESET%^%^GREEN%^ at Torm. It is a replica of Selune's wand that she wields as her chosen %^RED%^weapon%^RESET%^%^GREEN%^. Legend has it that in times of %^BOLD%^%^MAGENTA%^dire need%^RESET%^%^GREEN%^, the Lady may trade this wand for the original to aid her followers in battle.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set("strbonus",2);
	set("conbonus",2);
	set("chabonus",2);
	set_heart_beat(1);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RESET%^"+query_short()+" glows with the %^RESET%^%^CYAN%^s%^GREEN%^i%^CYAN%^l%^GREEN%^v%^CYAN%^e%^GREEN%^r%^CYAN%^y %^BLUE%^l%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^g%^BOLD%^h%^RESET%^%^BLUE%^t%^RESET%^ of %^BOLD%^%^CYAN%^Selune%^RESET%^.",ETO);
	tell_object(ETO,"%^RESET%^You feel %^YELLOW%^bathed%^RESET%^ in the divinity of %^BOLD%^%^CYAN%^Selune%^RESET%^ as you wield "+query_short()+".");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" seems %^BOLD%^%^CYAN%^lost%^RESET%^ after releasing "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^You feel lost as you release "+query_short()+".%^RESET%^");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" smashes "+targ->QCN+" with the %^YELLOW%^fury%^RED%^ of %^CYAN%^Selune!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You smash "+targ->QCN+" with the %^YELLOW%^fury%^RED%^ of %^CYAN%^Selune!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" smashes you with the %^YELLOW%^fury%^RED%^ of %^CYAN%^Selune!%^RESET%^");
		return roll_dice(2,10)+15;	}

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
				tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the %^BLUE%^presence%^WHITE%^ of the %^RESET%^%^CYAN%^L%^BOLD%^a%^RESET%^%^CYAN%^d%^BOLD%^y.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^"+query_short()+" %^YELLOW%^glows%^WHITE%^ with a divine light, and you feel the %^BLUE%^presence%^WHITE%^ of the %^RESET%^%^CYAN%^L%^BOLD%^a%^RESET%^%^CYAN%^d%^BOLD%^y.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the %^MAGENTA%^tug%^WHITE%^ of the %^CYAN%^%^BOLD%^F%^RESET%^%^CYAN%^o%^BOLD%^u%^RESET%^%^CYAN%^r M%^BOLD%^o%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^RESET%^.");
				tell_room(EETO, "%^BOLD%^%^WHITE%^You feel the %^MAGENTA%^tug%^WHITE%^ of the %^CYAN%^%^BOLD%^F%^RESET%^%^CYAN%^o%^BOLD%^u%^RESET%^%^CYAN%^r M%^BOLD%^o%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^ from "+query_short()+"%^BOLD%^%^WHITE%^ in the hands of "+ETOQCN+".%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^WHITE%^You sense the %^MAGENTA%^f%^CYAN%^o%^MAGENTA%^o%^CYAN%^t%^MAGENTA%^steps%^WHITE%^ of %^CYAN%^Selune%^WHITE%^ before you.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^A %^BLUE%^m%^RESET%^%^BLUE%^e%^BOLD%^a%^RESET%^%^BLUE%^n%^BOLD%^d%^RESET%^%^BLUE%^e%^BOLD%^r%^RESET%^%^BLUE%^i%^BOLD%^n%^RESET%^%^BLUE%^g %^BOLD%^%^GREEN%^path%^WHITE%^ of %^CYAN%^Selune's %^MAGENTA%^f%^CYAN%^o%^MAGENTA%^o%^CYAN%^t%^MAGENTA%^steps%^WHITE%^ appear before you and then fade.%^RESET%^", ({ETO}));
				break;
		}
	}
}
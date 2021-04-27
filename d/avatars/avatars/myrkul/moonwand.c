#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^W%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^d%^RESET%^%^CYAN%^ of the %^BOLD%^%^WHITE%^F%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^r M%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^s%^RESET%^");
	set_id(({ "mace", "rod", "wand" }));
	set_short("%^RESET%^%^CYAN%^W%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^d%^RESET%^%^CYAN%^ of the %^BOLD%^%^WHITE%^F%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^u%^RESET%^%^CYAN%^r M%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^S%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^m%^BOLD%^%^WHITE%^m%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^g %^BOLD%^%^WHITE%^W%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^d%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a %^WHITE%^replica%^CYAN%^ of the famous %^WHITE%^W%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^d%^RESET%^ of the %^RESET%^%^CYAN%^F%^BOLD%^%^WHITE%^ou%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^ M%^RESET%^%^CYAN%^oo%^BOLD%^%^WHITE%^ns%^CYAN%^, the weapon of the %^WHITE%^Goddess %^BLUE%^Selune%^CYAN%^. It glows with a soft %^RESET%^%^CYAN%^s%^GREEN%^i%^CYAN%^l%^GREEN%^v%^CYAN%^e%^GREEN%^r%^CYAN%^y%^BOLD%^%^CYAN%^ light, piercing even the deepest %^BLACK%^shadow%^CYAN%^. A little over a foot and a half in length, it is made of what must be %^BOLD%^%^WHITE%^m%^RESET%^%^GREEN%^oo%^BOLD%^%^WHITE%^n r%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^ck%^CYAN%^ and seems to move through the air without even the slightest resistance. It exudes the soft presence of the %^BLUE%^Seeker%^RESET%^.

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^MAGENTA%^In %^BLUE%^darkness%^MAGENTA%^, look to thy %^BOLD%^%^WHITE%^Lady%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(10000);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^This wand was forged in honor of %^BLUE%^Selune's%^CYAN%^ victory over %^BLACK%^Shar%^CYAN%^ at Torm. It is a replica of %^BLUE%^Selune's wand%^CYAN%^ that she wields in battle. Legend has it that in times of dire need, the %^WHITE%^Lady%^CYAN%^ may trade this wand for the original to aid her followers in battle.%^RESET%^

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
	tell_room(environment(ETO),"The wand %^RESET%^%^CYAN%^gl%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^mm%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^rs%^RESET%^ as "+ETOQCN+" wields "+query_short()+".",ETO);
	tell_object(ETO,"You feel stronger under the guidance of %^BOLD%^%^BLUE%^Selune%^RESET%^ as you wield "+query_short()+".");
	ETO->add_attack_bonus(2);
	ETO->add_attack_bonus(2);
	ETO->do_damage("torso",random(-50));
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"The presence of %^BOLD%^%^BLUE%^Selune%^RESET%^ fades as "+ETOQCN+" releases "+query_short()+".",ETO);
	tell_object(ETO,"You feel lost as you release "+query_short()+".");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" smashes "+targ->QCN+" with the %^RED%^f%^YELLOW%^u%^RED%^r%^YELLOW%^y%^BLUE%^ of %^CYAN%^Selune!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You %^RED%^strike%^BLUE%^ "+targ->QCN+" with the %^BOLD%^%^WHITE%^f%^YELLOW%^u%^WHITE%^r%^YELLOW%^y%^BLUE%^ of %^CYAN%^Selune!!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" smashes you with the %^RED%^f%^YELLOW%^u%^RED%^r%^YELLOW%^y%^BLUE%^ of %^CYAN%^Selune!!%^RESET%^");
		return roll_dice(2,6)+12;	}

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
				tell_object(ETO, "%^RESET%^%^CYAN%^The wand casts a %^BOLD%^%^WHITE%^silvery%^RESET%^%^CYAN%^ light.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^CYAN%^"+query_short()+" in "+ETOQCN+"'s hand casts a %^BOLD%^%^WHITE%^silvery%^RESET%^%^CYAN%^ light.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^RESET%^%^CYAN%^You feel the presence of %^BOLD%^%^BLUE%^Selune%^RESET%^");
				tell_room(EETO, "%^RESET%^%^CYAN%^You feel the presence of %^BOLD%^%^BLUE%^Selune%^RESET%^%^CYAN%^ emanating from "+query_short()+" wielded by "+ETOQCN+".%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^WHITE%^The moon pulls at your %^RED%^heart%^RESET%^.");
				tell_room(EETO, "%^BOLD%^%^WHITE%^The moon pulls at your %^RED%^heart%^WHITE%^ as "+ETOQCN+" holds "+query_short()+" in "+ETO->QP+" hand%^RESET%^.", ({ETO}));
				break;
		}
	}
}
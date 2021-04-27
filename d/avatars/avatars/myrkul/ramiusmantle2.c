#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^YELLOW%^C%^WHITE%^e%^YELLOW%^l%^WHITE%^e%^CYAN%^s%^WHITE%^t%^YELLOW%^i%^WHITE%^a%^CYAN%^l %^YELLOW%^M%^WHITE%^a%^YELLOW%^n%^CYAN%^t%^YELLOW%^l%^WHITE%^e%^RESET%^");
	set_id(({ "cloak", "mantle", "aura" }));
	set_short("%^YELLOW%^C%^WHITE%^e%^YELLOW%^l%^WHITE%^e%^CYAN%^s%^WHITE%^t%^YELLOW%^i%^WHITE%^a%^CYAN%^l %^YELLOW%^M%^WHITE%^a%^YELLOW%^n%^CYAN%^t%^YELLOW%^l%^WHITE%^e%^RESET%^");
	set_obvious_short("%^YELLOW%^B%^WHITE%^l%^YELLOW%^a%^WHITE%^z%^CYAN%^i%^WHITE%^n%^YELLOW%^g%^WHITE%^ M%^CYAN%^a%^WHITE%^n%^YELLOW%^t%^WHITE%^l%^CYAN%^e%^YELLOW%^ o%^WHITE%^f%^YELLOW%^ L%^WHITE%^i%^CYAN%^g%^WHITE%^h%^YELLOW%^t%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^A %^WHITE%^f%^YELLOW%^u%^WHITE%^r%^CYAN%^i%^WHITE%^o%^YELLOW%^u%^WHITE%^s%^YELLOW%^ s%^BLACK%^h%^YELLOW%^r%^BLACK%^o%^YELLOW%^u%^BLACK%^d%^YELLOW%^ of pure %^WHITE%^light%^YELLOW%^ ripples as if %^CYAN%^blown%^YELLOW%^ by some unseen wind. This is a %^CYAN%^m%^WHITE%^a%^CYAN%^n%^WHITE%^t%^CYAN%^l%^WHITE%^e%^YELLOW%^ of some %^WHITE%^heavenly%^YELLOW%^ origin. Apparently weightless, it seems to be %^BLACK%^somewhere%^YELLOW%^ between this plane and the next. It dispells all %^RESET%^%^MAGENTA%^shadows%^YELLOW%^ surrounding it, and no darkness is left unpierced. It appears on the one hand as if it was meant to be worn on the shoulders as some badge of %^RED%^rank%^YELLOW%^ and %^RED%^respect%^YELLOW%^. And yet it seems to %^RESET%^%^MAGENTA%^b%^BOLD%^%^CYAN%^l%^RESET%^%^MAGENTA%^u%^BOLD%^%^CYAN%^r%^YELLOW%^ and with almost a second %^WHITE%^sight%^YELLOW%^, it appears as %^YELLOW%^C%^WHITE%^e%^YELLOW%^l%^WHITE%^e%^CYAN%^s%^WHITE%^t%^YELLOW%^i%^WHITE%^a%^CYAN%^l %^CYAN%^wings!%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^S%^YELLOW%^a%^WHITE%^c%^YELLOW%^r%^WHITE%^i%^CYAN%^f%^WHITE%^i%^YELLOW%^c%^WHITE%^e%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(10000);
	set_lore(
@AVATAR
%^RESET%^Legend has it that the %^YELLOW%^Hosts of Heaven%^RESET%^ are comprised by %^BOLD%^%^WHITE%^legions%^RESET%^ of angels, ready to bring battle to %^RED%^evil%^RESET%^, %^MAGENTA%^vanquish%^RESET%^ demon and devil, and throw them back into the %^BOLD%^%^BLACK%^abyss%^RESET%^. Time has no meaning to the %^BOLD%^%^CYAN%^celestials%^RESET%^ for their enemy is eternal as is their resolve. Most mere mortals would never aspire to become one of their number, and fewer still have the %^BOLD%^%^WHITE%^p%^CYAN%^u%^WHITE%^r%^CYAN%^i%^WHITE%^t%^CYAN%^y%^WHITE%^ of purpose%^RESET%^ to stand as one of the host. Yet there have been mortals who served the %^BOLD%^%^WHITE%^host%^RESET%^ for a time, though not for long, for age touches mortals. This %^YELLOW%^mantle%^RESET%^ serves as a mark of their courage and purity of soul -- for though they may not bear the %^YELLOW%^wings of an angel%^RESET%^ in life, such wings are %^BOLD%^%^RED%^etched%^RESET%^ upon their souls.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set_heart_beat(1);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^You hear the %^RESET%^%^CYAN%^slow chant%^YELLOW%^ of %^WHITE%^a%^CYAN%^n%^WHITE%^g%^CYAN%^e%^WHITE%^l%^CYAN%^s%^WHITE%^!!%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You hear the %^RESET%^%^CYAN%^slow chant%^YELLOW%^ of %^WHITE%^a%^CYAN%^n%^WHITE%^g%^CYAN%^e%^WHITE%^l%^CYAN%^s%^WHITE%^!!%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^As "+ETOQCN+" is %^RED%^bereft%^RESET%^ of "+query_short()+", "+ETOQCN+" seems infused with a %^RESET%^%^CYAN%^great %^BOLD%^%^WHITE%^w%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^y%^RESET%^ %^CYAN%^grayness.%^RESET%^",ETO);
	tell_object(ETO,"You suddenly feel very %^YELLOW%^alone%^RESET%^ and the internal peace inside your soul seems %^RED%^rent%^RESET%^ with unease.");
	ETO->set_property("magic resistance",-10);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^RESET%^"+who->QCN+" %^YELLOW%^levels a massive blow at %^RESET%^"+ETOQCN+"%^YELLOW%^, yet the attack seems to pass %^GREEN%^harmlessly%^YELLOW%^ through the "+query_short()+" as if it were made of %^RESET%^%^CYAN%^insubstantial ether!%^RESET%^",({ETO,who}));
	tell_object(ETO,"^YELLOW%^You feel %^CYAN%^peaceful%^YELLOW%^ as the %^RED%^devastating blow%^YELLOW%^ levered by %^RESET%^"+who->QCN+"%^YELLOW%^ passes through you harmlessly.%^RESET%^");
	tell_object(who,"%^YELLOW%^Your blow passes harmlessly through %^RESET%^"+ETOQCN+"%^YELLOW%^ who is bathed in %^WHITE%^heavenly light!%^YELLOW%^ from "+query_short()+"%^RESET%^");
return (damage*100)/100;	}

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
		switch(random(5)) 
		{
			case 0:
				tell_object(ETO, "You feel the %^YELLOW%^call%^RESET%^ of the %^YELLOW%^Celestial Host%^RESET%^.");
				tell_room(EETO, "%^RESET%^"+ETOQCN+" %^YELLOW%^glows%^RESET%^ with a %^YELLOW%^divine %^WHITE%^l%^CYAN%^i%^WHITE%^g%^CYAN%^h%^WHITE%^t!!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^RESET%^The %^CYAN%^sense%^RESET%^ of %^CYAN%^t%^GREEN%^i%^CYAN%^mel%^GREEN%^e%^CYAN%^ss%^GREEN%^n%^CYAN%^ess%^RESET%^ overcomes your %^YELLOW%^vision%^RESET%^ of the present.%^RESET%^");
				tell_room(EETO, "%^YELLOW%^W%^BLACK%^r%^YELLOW%^e%^WHITE%^a%^YELLOW%^t%^BLACK%^h%^YELLOW%^e%^WHITE%^d%^RESET%^ in a %^BOLD%^%^CYAN%^divine %^YELLOW%^l%^CYAN%^i%^YELLOW%^ght%^RESET%^, "+ETOQCN+" seems to %^RESET%^%^MAGENTA%^fade%^RESET%^ momentarily into a %^CYAN%^etherial outline%^RESET%^ before returning.", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^RESET%^%^CYAN%^You feel yourself %^BOLD%^%^WHITE%^unfurl%^YELLOW%^ mighty %^WHITE%^wings%^RESET%^%^CYAN%^ of the %^BOLD%^%^WHITE%^H%^YELLOW%^e%^WHITE%^a%^CYAN%^v%^WHITE%^e%^YELLOW%^n%^WHITE%^l%^CYAN%^y%^WHITE%^ H%^YELLOW%^o%^WHITE%^s%^CYAN%^t%^WHITE%^!!%^RESET%^");
				tell_room(EETO, "%^RESET%^"+ETOQCN+" shifts %^CYAN%^half-way%^RESET%^ into another plane, and "+ETO->QP+" %^RESET%^%^MAGENTA%^other-worldly image %^BOLD%^%^WHITE%^unfurls%^YELLOW%^ mighty %^WHITE%^wings%^RESET%^%^CYAN%^ of the %^BOLD%^%^WHITE%^H%^YELLOW%^e%^WHITE%^a%^CYAN%^v%^WHITE%^e%^YELLOW%^n%^WHITE%^l%^CYAN%^y%^WHITE%^ H%^YELLOW%^o%^WHITE%^s%^CYAN%^t%^WHITE%^!!%^RESET%^", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^RESET%^"+query_short()+" extends %^YELLOW%^tendrils%^RESET%^ of %^YELLOW%^heavenly light%^RESET%^ into the %^BOLD%^%^BLACK%^shadows.%^RESET%^");
				tell_room(EETO, "%^RESET%^"+query_short()+" worn by "+ETOQCN+" extends %^YELLOW%^tendrils%^RESET%^ of %^YELLOW%^heavenly light%^RESET%^ into the %^BOLD%^%^BLACK%^shadows.%^RESET%^", ({ETO}));
				break;
			case 4:
				tell_object(ETO, "%^BOLD%^%^WHITE%^A %^CYAN%^wave%^WHITE%^ of %^YELLOW%^h%^RED%^u%^YELLOW%^n%^RED%^g%^YELLOW%^e%^RED%^r%^WHITE%^ for the %^YELLOW%^p%^WHITE%^e%^YELLOW%^a%^WHITE%^c%^YELLOW%^e%^WHITE%^ of the %^CYAN%^divine%^WHITE%^ washes over you!%^RESET%^");
				tell_room(EETO, "%^YELLOW%^"+query_short()+" glows brightly with %^WHITE%^holy light%^YELLOW%^ and "+ETOQCN+" seems to %^WHITE%^s%^CYAN%^w%^WHITE%^o%^CYAN%^o%^WHITE%^n%^YELLOW%^ with %^RESET%^%^CYAN%^longing.%^RESET%^", ({ETO}));
				break;
		}
	}
}
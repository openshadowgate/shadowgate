#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("%^BOLD%^%^CYAN%^c%^WHITE%^r%^RESET%^%^CYAN%^y%^BOLD%^s%^WHITE%^t%^RESET%^%^CYAN%^a%^BOLD%^l %^RESET%^%^CYAN%^heart%^RESET%^");
	set_id(({ "crystal", "heart", "crystal heart" }));
	set_short("%^BOLD%^%^CYAN%^c%^WHITE%^r%^RESET%^%^CYAN%^y%^BOLD%^s%^WHITE%^t%^RESET%^%^CYAN%^a%^BOLD%^l %^RESET%^%^CYAN%^heart%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^e%^CYAN%^a%^RESET%^%^CYAN%^rt-s%^BOLD%^%^WHITE%^h%^RESET%^%^CYAN%^a%^BOLD%^p%^RESET%^%^CYAN%^ed c%^BOLD%^%^WHITE%^r%^CYAN%^y%^RESET%^%^CYAN%^st%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^l%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This is a small shard of %^BOLD%^%^BLUE%^i%^CYAN%^c%^BLUE%^y b%^WHITE%^l%^BLUE%^ue%^RESET%^%^CYAN%^ crystal, perhaps with a faint glow. It seems to %^MAGENTA%^throb%^CYAN%^ and pulse "
	"in time like a %^RED%^h%^MAGENTA%^e%^RED%^a%^MAGENTA%^r%^RED%^t%^CYAN%^. Tiny %^BOLD%^%^BLACK%^runes%^RESET%^%^CYAN%^ are inscribed in the facets of the gem.%^RESET%^
"
	);
	set_value(2500);
	set_lore("%^BOLD%^%^CYAN%^This is a %^RED%^psion's%^CYAN%^ stone that has grown so powerful as to give %^YELLOW%^life%^CYAN%^ itself. Only a %^GREEN%^madman%^CYAN%^ or %^RED%^genius%^CYAN%^ or truly %^RESET%^%^"
	"MAGENTA%^desperate%^BOLD%^%^CYAN%^ would use such a stone because it replaces the live beating heart. In principle this could extend life, perhaps unnaturally so. However the removal of such a stone w"
	"ould mean certain %^BLACK%^death%^CYAN%^ so truly wearing such an item is final decision.%^RESET%^
"
	);
    set_property("lore difficulty",20);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_type("clothing");
}

int wear_func(){
	tell_room(environment(ETO),"Life returns to "+ETOQCN+" as "+query_short()+" replaces a missing heart and starts beating.",ETO);
	tell_object(ETO,"As you slip "+query_short()+" into the hole in your chest, you feel full of %^YELLOW%^life%^RESET%^, and health returns to you as the heart begins %^RED%^beating%^RESET%^.");
	ETO->do_damage("torso",random(-200));
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^Life%^RED%^ slips from "+ETOQCN+"%^BOLD%^%^RED%^ as "+query_short()+"%^BOLD%^%^RED%^ is removed leaving a gaping hole in its place!!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel %^YELLOW%^life%^RED%^ slip from you as your "+query_short()+" is removed!!%^RESET%^");
	ETO->do_damage("torso",random(200));
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETOQCN+" is shifted by "+query_short()+"%^BOLD%^%^CYAN%^ into the %^YELLOW%^astral plane%^CYAN%^ momentarily before "+ETOQCN+" is struck by "+who->QCN+"!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You are shifted by "+query_short()+"%^BOLD%^%^CYAN%^ into the %^YELLOW%^astral plane%^CYAN%^ momentarily before you are struck!%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^"+ETOQCN+" is shifted by "+query_short()+"%^BOLD%^%^CYAN%^ into the %^YELLOW%^astral plane%^CYAN%^ momentarily before you can hit!%^RESET%^");
return (damage*0)/100;	}

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
		switch(random(4)) 
		{
			case 0:
				tell_object(ETO, ""+query_short()+" %^RESET%^%^MAGENTA%^t%^RED%^h%^MAGENTA%^r%^RED%^o%^MAGENTA%^b%^RED%^s%^CYAN%^ in your chest.%^RESET%^");
tell_room(EETO, ""+query_short()+" %^BOLD%^%^GREEN%^p%^RED%^u%^GREEN%^ls%^RED%^e%^GREEN%^s%^RESET%^%^CYAN%^ and %^RESET%^%^MAGENTA%^t%^RED%^h%^MAGENTA%^r%^RED%^o%^MAGENTA%^b%^RED%^s%^CYAN%^ in "+ETO->QCN+"'s chest.%^RESET%^", ({ETO})); 
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^RED%^You %^GREEN%^feel%^RED%^ the steady %^BLACK%^d%^RED%^rum%^BLACK%^b%^RED%^ea%^BLACK%^t%^RED%^ of your "+query_short()+".%^RESET%^");
tell_room(EETO, "%^BOLD%^%^RED%^You %^GREEN%^feel%^RED%^ the steady %^BLACK%^d%^RED%^rum%^BLACK%^b%^RED%^ea%^BLACK%^t%^RED%^ of "+query_short()+" in "+ETO->QP+" chest.%^RESET%^", ({ETO})); 
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^GREEN%^Your steady %^RED%^heartbeat%^GREEN%^ never changes in %^CYAN%^t%^RESET%^%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^, and for a moment, you feel %^WHITE%^de%^BLACK%^t%^WHITE%^ac%^BLACK%^h%^WHITE%^ed%^GREEN%^, and utterly %^RESET%^%^ORANGE%^emotionless.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" %^BOLD%^%^GREEN%^seems %^WHITE%^de%^BLACK%^t%^WHITE%^ac%^BLACK%^h%^WHITE%^ed%^GREEN%^, and utterly %^RESET%^%^ORANGE%^emotionless.%^RESET%^", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^BOLD%^%^WHITE%^The room %^YELLOW%^echos%^WHITE%^ with the steady %^YELLOW%^tap-%^RED%^tap-%^BLUE%^tapping%^WHITE%^ away of your "+query_short()+".%^RESET%^");
tell_room(EETO, "%^BOLD%^%^WHITE%^The room %^YELLOW%^echos%^WHITE%^ with the steady %^YELLOW%^tap-%^RED%^tap-%^BLUE%^tapping%^WHITE%^ away of "+query_short()+" in "+ETO->QCN+"'s chest.%^RESET%^", ({ETO})); 
				break;
		}
	}
}

#include <std.h>
inherit "/d/common/obj/clothing/shirt";

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^YELLOW%^s%^RESET%^%^ORANGE%^h%^YELLOW%^r%^RESET%^%^ORANGE%^e%^YELLOW%^d%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^d %^CYAN%^s%^GREEN%^h%^CYAN%^i%^GREEN%^r%^CYAN%^t%^RESET%^");
	set_id(({ "shirt" }));
	set_short("%^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^YELLOW%^s%^RESET%^%^ORANGE%^h%^YELLOW%^r%^RESET%^%^ORANGE%^e%^YELLOW%^d%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^d %^CYAN%^s%^GREEN%^h%^CYAN%^i%^GREEN%^r%^CYAN%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^z%^GREEN%^o%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^e %^YELLOW%^s%^RESET%^%^ORANGE%^h%^YELLOW%^r%^RESET%^%^ORANGE%^e%^YELLOW%^d%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^d %^CYAN%^s%^GREEN%^h%^CYAN%^i%^GREEN%^r%^CYAN%^t%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This once %^RED%^fine%^CYAN%^ shirt has been %^MAGENTA%^torn%^CYAN%^ asunder by %^RESET%^claws.%^CYAN%^ It still has a collar, but one sleeve is missing. Deep rents criss-cross the ta"
	"ttered remains. It appears to be coated in some kind of %^GREEN%^slimy ichor.%^RESET%^
"
	);
	set_value(0);
	set_lore("Ethius was once a devout follower of Cyric, but he decided to leave when Cyrics dogma changed. Alzar the high priest hunted Ethius down and trapped his soul in a bottle. Cyric leveled a curse on Ethiu"
	"s that his corpse should remain a zombie and forever try to reclaim his soul. This is the shirt that Ethius wore on that fateful day.
"
	);
    set_property("lore difficulty",10);
    set("strbonus",2);
    set("chabonus",-4);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^YELLOW%^"+who->QCN+"%^YELLOW%^ chokes on a %^GREEN%^cloud of gas%^YELLOW%^ emanating from "+query_short()+"%^YELLOW%^ worn by "+ETOQCN+".%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^"+who->QCN+"%^YELLOW%^ chokes on a %^GREEN%^cloud of gas%^YELLOW%^ emanating from "+query_short()+".%^RESET%^");
	tell_object(who,"%^YELLOW%^You choke on a %^GREEN%^cloud of gas%^YELLOW%^ emanating from "+query_short()+"%^YELLOW%^ worn by "+ETOQCN+".%^RESET%^");
		who->do_damage("torso",roll_dice(20,2));
return damage;	}

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
		switch(random(4)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^GREEN%^A %^YELLOW%^miasma%^GREEN%^ of horrible stench fills the %^WHITE%^air%^RESET%^.");
				tell_room(EETO, "%^BOLD%^%^GREEN%^A %^YELLOW%^miasma%^GREEN%^ of horrible stench fills the %^WHITE%^air%^RESET%^.", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^RESET%^%^MAGENTA%^A hideous cloud of %^BOLD%^%^BLACK%^flies%^RESET%^%^MAGENTA%^ gathers nearby, searching for %^RED%^dead flesh%^MAGENTA%^ to infest.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^MAGENTA%^A hideous cloud of %^BOLD%^%^BLACK%^flies%^RESET%^%^MAGENTA%^ gathers nearby, searching for %^RED%^dead flesh%^MAGENTA%^ to infest.%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RED%^pervasive%^CYAN%^ sense of %^BLACK%^dread%^CYAN%^ passes through you as if some %^BLUE%^supernatural %^RED%^evil%^CYAN%^ lurks near you.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RED%^pervasive%^CYAN%^ sense of %^BLACK%^dread%^CYAN%^ passes through you as if some %^BLUE%^supernatural %^RED%^evil%^CYAN%^ lurks near you.%^RESET%^", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^YELLOW%^Hmm, that %^MAGENTA%^perfume%^YELLOW%^, you smell a distinct %^GREEN%^fragrance%^YELLOW%^ - %^RESET%^%^ORANGE%^eau%^YELLOW%^ de %^RED%^Z%^RESET%^%^RED%^o%^BOLD%^m%^RESET%^%^RED%^b%^BOLD%^i%^RESET%^%^RED%^e%^BOLD%^.%^RESET%^");
				tell_room(EETO, "%^YELLOW%^Hmm, that %^MAGENTA%^perfume%^YELLOW%^, you smell a distinct %^GREEN%^fragrance%^YELLOW%^ - %^RESET%^%^ORANGE%^eau%^YELLOW%^ de %^RED%^Z%^RESET%^%^RED%^o%^BOLD%^m%^RESET%^%^RED%^b%^BOLD%^i%^RESET%^%^RED%^e%^BOLD%^.%^RESET%^", ({ETO}));
				break;
		}
	}
}
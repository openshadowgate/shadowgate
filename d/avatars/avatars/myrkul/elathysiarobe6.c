#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
	::create();
	set_name("robes");
	set_id(({ "robes", " robes of the archmagi" }));
	set_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RESET%^%^RED%^b%^BOLD%^e%^MAGENTA%^s %^RESET%^%^CYAN%^o%^BOLD%^f %^RESET%^%^CYAN%^t%^BOLD%^h%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^N%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^e %^BOLD%^%^BLACK%^S%^RESET%^e%^BOLD%^%^BLACK%^c%^RESET%^r%^BOLD%^%^BLACK%^e%^RESET%^t%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RESET%^%^RED%^b%^BOLD%^e%^MAGENTA%^s%^BOLD%^%^RED%^ o%^RESET%^%^RED%^f %^BOLD%^t%^MAGENTA%^h%^RESET%^%^RED%^e %^BOLD%^%^MAGENTA%^A%^RED%^r%^RESET%^%^RED%^c%^BOLD%^h%^MAGENTA%^m%^RESET%^%^RED%^a%^BOLD%^g%^MAGENTA%^i%^RESET%^");
	set_long("%^RESET%^%^CYAN%^These %^RESET%^%^RED%^f%^BOLD%^i%^MAGENTA%^r%^RESET%^%^RED%^e%^BOLD%^y red robes%^RESET%^%^CYAN%^ resonate with a depth of %^BOLD%^%^BLACK%^m%^RESET%^y%^BOLD%^%^BLACK%^s%^RESET%^t%^BO"
	"LD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^ and %^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^id%^BOLD%^d%^RESET%^%^GREEN%^en p%^BOLD%^o%^RESET%^%^GREEN%^wer%^CYAN%^. The robes have long sleeves"
	", a high collar, and extremely light fabric. Ancient %^MAGENTA%^glyphs%^CYAN%^ appear and fade across the fabric of the robe like a %^YELLOW%^t%^RESET%^%^ORANGE%^a%^YELLOW%^p%^RESET%^%^ORANGE%^e%^YELL"
	"OW%^s%^RESET%^%^ORANGE%^t%^YELLOW%^r%^RESET%^%^ORANGE%^y%^CYAN%^, and doubtless would reveal long histories and hidden knowledge if ever they could be understood. The robes are of an ancient, perhaps "
	"%^BOLD%^%^GREEN%^e%^YELLOW%^l%^GREEN%^ven s%^YELLOW%^t%^GREEN%^yle%^RESET%^%^CYAN%^, long gone out of favor a thousand years ago. Nevertheless they are clearly the garb of an %^BOLD%^%^MAGENTA%^A%^RED"
	"%^r%^RESET%^%^RED%^c%^BOLD%^%^MAGENTA%^h%^RED%^m%^RESET%^%^RED%^a%^BOLD%^g%^MAGENTA%^i%^RESET%^%^CYAN%^.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^RESET%^%^CYAN%^S%^BOLD%^a%^RESET%^%^CYAN%^ulk%^GREEN%^ was an elven Archmage of incredible power and both veteran and survivor of the Godswars well over a thousand years ago. He and three intrepid f"
	"riends sought to protect the Temple of Eldath from an encroaching Willow Tree that had been corrupted. The Willow was an ancient force of nature and it could not be stopped by blade or spell or bow. F"
	"inally in an act of desperation, Saulk called down an inferno which incinerated himself, his friends, and all life in a key passage that prevented the advance of the encroaching tree spirit. The act w"
	"as even more terrible because it also turned Saulk into an elven lich called a Balenorn. A thousand years later the Balenorn was freed when %^BOLD%^Aashaenael%^RESET%^%^GREEN%^ the elven warrior, %^YE"
	"LLOW%^Elathysia%^RESET%^%^GREEN%^ the sorceress, %^BOLD%^%^BLACK%^Aunuit%^RESET%^%^GREEN%^ the drow queen and %^BOLD%^%^BLACK%^Ryzan%^RESET%^%^GREEN%^ her consort defeated the Willow tree. --- The rob"
	"es were what was left of Saulk, the Archmagi of the %^BOLD%^%^BLACK%^N%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^ S%^RESET%^e%^BOLD%^%^BLACK%^cr%^RESET%^e%^BOLD%^%^BLACK%^ts%^RESET%^%^GREE"
	"N%^. He kept great secrets of the godswars including spells of desperation, utter destruction and the power over death itself -- the creation of a lich.%^RESET%^ 
"
	);
    set_property("lore difficulty",20);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel many mysteries become clear to you as you wear the robes.");
	ETO->set_property("magic resistance",10);
	ETO->add_skill_bonus("spellcraft",4);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel the world become full of confusion as you remove the robes.");
	ETO->set_property("magic resistance",-10);
	ETO->add_skill_bonus("spellcraft",-4);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^RESET%^%^CYAN%^"+ETOQCN+" seems to %^BOLD%^know%^RESET%^%^CYAN%^ where you%^RESET%^%^CYAN%^ are going to %^BOLD%^%^RED%^strike%^RESET%^%^CYAN%^, and "+ETOQCN+" %^BOLD%^%^GREEN%^steps out of the way.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^CYAN%^You %^BOLD%^know%^RESET%^%^CYAN%^ where "+who->QCN+"%^RESET%^%^CYAN%^ is going to %^BOLD%^%^RED%^strike%^RESET%^%^CYAN%^ before your opponent even thinks it, and you %^BOLD%^%^GREEN%^step out of the way.%^RESET%^");
	tell_object(who,"%^RESET%^%^CYAN%^"+ETOQCN+" seems to %^BOLD%^know%^RESET%^%^CYAN%^ where you%^RESET%^%^CYAN%^ are going to %^BOLD%^%^RED%^strike%^RESET%^%^CYAN%^, and "+ETOQCN+" %^BOLD%^%^GREEN%^steps out of the way.%^RESET%^");
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
	 if(random(1000) > 998) 
	 {
		switch(random(1)) 
		{
			case 0:
                                tell_object(ETO, "%^RESET%^%^CYAN%^G%^BOLD%^l%^RESET%^%^CYAN%^y%^BOLD%^p%^RESET%^%^CYAN%^hs%^GREEN%^ of %^YELLOW%^power%^RESET%^%^GREEN%^ and %^YELLOW%^might%^RESET%^%^GREEN%^ shift and swirl on "+query_short()+"%^RESET%^%^GREEN%^ worn by you%^RESET%^%^GREEN%^ with %^BOLD%^%^MAGENTA%^h%^RESET%^%^MAGENTA%^i%^BOLD%^d%^RESET%^%^MAGENTA%^d%^BOLD%^e%^RESET%^%^MAGENTA%^n%^RESET%^%^GREEN%^ meaning.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^CYAN%^G%^BOLD%^l%^RESET%^%^CYAN%^y%^BOLD%^p%^RESET%^%^CYAN%^hs%^GREEN%^ of %^YELLOW%^power%^RESET%^%^GREEN%^ and %^YELLOW%^might%^RESET%^%^GREEN%^ shift and swirl on "+query_short()+"%^RESET%^%^GREEN%^ worn by "+ETOQCN+"%^RESET%^%^GREEN%^ with %^BOLD%^%^MAGENTA%^h%^RESET%^%^MAGENTA%^i%^BOLD%^d%^RESET%^%^MAGENTA%^d%^BOLD%^e%^RESET%^%^MAGENTA%^n%^RESET%^%^GREEN%^ meaning.%^RESET%^", ({ETO}));
				break;
		}
	}
}

#include <std.h>
inherit "/d/common/obj/jewelry/bracelet";

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^ar%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^ba%^RESET%^%^WHITE%^n%^RESET%^%^GREEN%^d%^RESET%^");
	set_id(({ "armband" }));
	set_short("%^RESET%^%^GREEN%^de%^RESET%^%^WHITE%^l%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^t%^RESET%^%^GREEN%^e j%^RESET%^%^WHITE%^ad%^RESET%^%^GREEN%^e ar%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^ba%^RESET%^%^WHITE%^n%^RESET%^%^GREEN%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^de%^RESET%^%^WHITE%^l%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^t%^RESET%^%^GREEN%^e j%^RESET%^%^WHITE%^ad%^RESET%^%^GREEN%^e ar%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^ba%^RESET%^%^WHITE%^n%^RESET%^%^GREEN%^d%^RESET%^");
	set_long("%^RESET%^%^GREEN%^This is a fine armb%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^nd, created %^WHITE%^f%^GREEN%^rom a solid piece of ch%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^o%^GREEN%^ti%^WHITE%^c%^GREEN%^al%^BO"
	"LD%^%^WHITE%^l%^RESET%^%^GREEN%^y patt%^BOLD%^%^WHITE%^%^RESET%^%^GREEN%^eren%^BOLD%^e%^RESET%^%^GREEN%^d j%^RESET%^%^WHITE%^a%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^e.  The gr%^BOLD%^%^GREEN%^ee%^RESET%^"
	"%^GREEN%^n of the st%^RESET%^%^WHITE%^o%^RESET%^%^GREEN%^ne is divided by %^RESET%^%^WHITE%^pu%^BOLD%^r%^RESET%^e white %^GREEN%^struc%^BOLD%^%^WHITE%^t%^RESET%^%^GREEN%^ures which look almost cr%^RES"
	"ET%^%^WHITE%^ys%^RESET%^%^GREEN%^tal%^RESET%^%^WHITE%^l%^RESET%^%^GREEN%^ine in n%^BOLD%^a%^RESET%^%^GREEN%^ture.  The texture of the %^BOLD%^c%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^l%^RESET%^o%^RESET%^%"
	"^GREEN%^r %^RESET%^%^WHITE%^s %^RESET%^%^GREEN%^seem nearly timeless in their beauty. The ba%^BOLD%^%^WHITE%^n%^RESET%^%^GREEN%^d is polished perfectly sm%^RESET%^%^WHITE%^o%^BOLD%^%^GREEN%^o%^RESET%^"
	"%^GREEN%^th, with a delicate, elli%^BOLD%^%^WHITE%^p%^RESET%^t%^RESET%^%^GREEN%^ic%^RESET%^%^WHITE%^a%^RESET%^%^GREEN%^l cross section.  The band %^RESET%^%^WHITE%^w%^RESET%^%^GREEN%^oul%^BOLD%^%^WHIT"
	"E%^d %^RESET%^%^GREEN%^most likely be fit to a woman's slender arm, and could probably be fit over a sleeve.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^RESET%^%^CYAN%^This %^GREEN%^artifact%^RESET%^%^CYAN%^ was a gift to the mighty elf lord %^BOLD%^%^WHITE%^M%^CYAN%^i%^WHITE%^t%^CYAN%^h%^WHITE%^r%^CYAN%^a%^WHITE%^s%^RESET%^%^CYAN%^ from the ancient"
	" crafter and elder of %^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^y%^BOLD%^n%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^a%^YELLOW%^ E%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^r%^"
	"RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^a%^YELLOW%^l%^RESET%^%^CYAN%^ for his service in defense of the village against the %^BOLD%^%^BLACK%^dark%^RESET%^%^CYAN%"
	"^ and %^RED%^evil%^RESET%^%^CYAN%^ force of thieves that attacked the town.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+"%^BOLD%^%^GREEN%^ seems more %^MAGENTA%^confident%^GREEN%^ wearing "+query_short()+"%^BOLD%^%^GREEN%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You feel %^MAGENTA%^confident%^GREEN%^ with "+query_short()+"%^GREEN%^ on your arm.%^RESET%^");
	ETO->add_skill_bonus("influence",2);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" seems to be diminished and more ordinary without "+query_short()+".",ETO);
	tell_object(ETO,"You feel a shade less confident as you remove "+query_short()+".");
	ETO->add_skill_bonus("influence",-2);
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
         if(random(1000) > 998)
	 {
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^GREEN%^The "+query_short()+"%^BOLD%^%^GREEN%^ worn by "+ETOQCN+"%^BOLD%^%^GREEN%^ %^CYAN%^s%^WHITE%^h%^CYAN%^i%^WHITE%^m%^CYAN%^m%^WHITE%^e%^CYAN%^r%^WHITE%^s%^GREEN%^ and %^RESET%^%^CYAN%^g%^GREEN%^l%^BOLD%^i%^RESET%^%^CYAN%^t%^GREEN%^t%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^s%^BOLD%^ g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^YELLOW%^ attractively%^GREEN%^ in the light.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^GREEN%^The "+query_short()+"%^BOLD%^%^GREEN%^ worn by "+ETOQCN+"%^BOLD%^%^GREEN%^ %^CYAN%^s%^WHITE%^h%^CYAN%^i%^WHITE%^m%^CYAN%^m%^WHITE%^e%^CYAN%^r%^WHITE%^s%^GREEN%^ and %^RESET%^%^CYAN%^g%^GREEN%^l%^BOLD%^i%^RESET%^%^CYAN%^t%^GREEN%^t%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^s%^BOLD%^ g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^YELLOW%^ attractively%^GREEN%^ in the light.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^GREEN%^You feel %^YELLOW%^d%^MAGENTA%^a%^YELLOW%^z%^MAGENTA%^z%^YELLOW%^l%^MAGENTA%^i%^YELLOW%^n%^MAGENTA%^g%^YELLOW%^l%^MAGENTA%^y%^GREEN%^ beautiful with "+query_short()+"%^BOLD%^%^GREEN%^ on your arm.%^RESET%^");
                                tell_room(EETO, "%^BOLD%^%^GREEN%^"+ETOQCN+"%^BOLD%^%^GREEN%^ looks %^YELLOW%^d%^MAGENTA%^a%^YELLOW%^z%^MAGENTA%^z%^YELLOW%^l%^MAGENTA%^i%^YELLOW%^n%^MAGENTA%^g%^YELLOW%^l%^MAGENTA%^y%^GREEN%^ beautiful with "+query_short()+"%^BOLD%^%^GREEN%^ on "+ETO->QP+"%^BOLD%^%^GREEN%^ arm.%^RESET%^", ({ETO}));
				break;
		}
	}
}

#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_id(({ "aura" }));
	set_short("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^");
	set_long("%^BOLD%^%^RED%^This %^BLACK%^hazy%^RED%^ pocket of air seems to %^RESET%^%^BLUE%^s%^BOLD%^c%^RESET%^%^CYAN%^r%^BOLD%^a%^GREEN%^m%^RESET%^%^GREEN%^b%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^RE"
	"D%^ everything that passes under its %^YELLOW%^entropic%^RED%^ domain. A perpetual source of chaos, the presence sucks the order out of everything around it. At times flowers bloom or wither out of se"
	"ason right before your eyes. Knots untie and re-tie themselves. Works of art are distorted, with straight lines never to be seen again. The %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^"
	"GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^%^BOLD%^%^RED%^ is centered on a single shard of %^WHITE%^bone%^RED%^ and might be worn around the neck.%"
	"^RESET%^
"
	);
	set_value(10000);
	set_lore("The %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^ grants youth to its wearer by transferri"
	"ng the disorder of the body to the environment. Maintaining ones sanity while living in a chaos field would require a person of great wisdom. Of course, a person of great wisdom might not necessarily "
	"want to wear an %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^. The history of the Aura and"
	" its creator is Murky at best, with various sects of %^BOLD%^%^CYAN%^Tymora%^RESET%^, %^MAGENTA%^Beshaba%^RESET%^, and %^BOLD%^%^BLACK%^Cyric%^RESET%^ claiming it at various times. The Aura is conside"
	"red a holy relic by clergy of all three deities.
"
	);
    set_property("lore difficulty",30);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^seems to grow %^YELLOW%^younger%^RESET%^ right before your eyes, bathed in the power of the %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^!",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You feel %^YELLOW%^younger%^GREEN%^ and full of %^CYAN%^strength%^YELLOW%^ as you feel the %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^ %^BOLD%^%^GREEN%^around you!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^seems to grow %^RED%^older%^RESET%^ right before your eyes, as the power of the %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^ is removed!",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel %^YELLOW%^older%^RED%^ and full of %^RESET%^%^MAGENTA%^weakness%^BOLD%^%^RED%^ as you feel the %^RESET%^%^RED%^A%^BOLD%^u%^MAGENTA%^r%^YELLOW%^a%^RESET%^%^GREEN%^ o%^BOLD%^f%^RESET%^%^CYAN%^ C%^BOLD%^ha%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^s%^RESET%^ %^BOLD%^%^RED%^leave you!%^RESET%^");
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
		switch(random(10)) 
		{
			case 0:
				tell_object(ETO, "%^YELLOW%^You hear a %^BLACK%^whisper:%^RED%^ Break not into open rebellion, for when hosts march, all faiths and gods awaken. It is better by far to fell one foe at a time and keep all folk afraid, uneasy, in constant strife.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^YELLOW%^You hear a %^BLACK%^whisper:%^RED%^ Death to traitors.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^YELLOW%^You hear a %^BLACK%^whisper:%^RED%^ Fear and obey those in authority - but if they are weak or given to pursuing airy goals of vague goodness, slay them.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^YELLOW%^You hear a %^RESET%^%^MAGENTA%^whisper:%^BOLD%^%^BLUE%^ Bad things happen to everyone.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 4:
				tell_object(ETO, "%^YELLOW%^You hear a %^RESET%^%^MAGENTA%^whisper:%^BOLD%^%^BLUE%^ Too much good luck is a bad thing, and to even it out, the wise should plan to undermine the fortunate.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 5:
				tell_object(ETO, "%^YELLOW%^You hear a %^RESET%^%^MAGENTA%^whisper:%^BOLD%^%^BLUE%^ Whatever happens, it can only get worse.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 6:
				tell_object(ETO, "%^YELLOW%^You hear a %^CYAN%^whisper:%^BOLD%^%^GREEN%^ One should be bold, for to be bold is to live.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 7:
				tell_object(ETO, "%^YELLOW%^You hear a %^CYAN%^whisper:%^BOLD%^%^GREEN%^  A brave heart and a willingness to take risks beat out a carefully wrought plan nine times out of ten.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 8:
				tell_object(ETO, "%^YELLOW%^You hear a %^CYAN%^whisper:%^BOLD%^%^GREEN%^ Place yourself in the hands of fate and trust to your own luck.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems distracted by an unseen voice.", ({ETO}));
				break;
			case 9:
				tell_object(ETO, "%^YELLOW%^All growing things around you seem to %^RESET%^%^ORANGE%^wither%^YELLOW%^ with %^BLACK%^age%^YELLOW%^ right before your eyes.%^RESET%^");
				tell_room(EETO, "%^YELLOW%^All growing things around "+ETOQCN+" seem to %^RESET%^%^ORANGE%^wither%^YELLOW%^ with %^BLACK%^age%^YELLOW%^ right before your eyes.%^RESET%^", ({ETO}));
				break;
		}
	}
}
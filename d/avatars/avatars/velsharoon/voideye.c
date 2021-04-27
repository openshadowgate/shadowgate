#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^O%^%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^of the %^Vo%^WHITE%^i%^BLACK%^d%^RESET%^");
	set_id(({ "eye", "void", "stone", "oculus" }));
	set_short("%^BOLD%^%^BLACK%^O%^%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^of the Vo%^WHITE%^i%^BLACK%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^stone of utter %^BOLD%^%^BLACK%^darkness%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This stone, if you can call it a stone, seems to absorb %^YELLOW%^light %^RESET%^%^GREEN%^into it. The stone itself is near weightless yet %^BOLD%^%^CYAN%^chillingly %^WHITE%^cold %^RESET%^%^GREEN%^to the touch. Peering achingly close to the stone there are subtle shades within. %^BOLD%^%^RED%^Vol%^BLACK%^c%^RED%^anic %^BLACK%^black%^RESET%^%^GREEN%^ envelopes what can only be described as putrescent %^MAGENTA%^mauve %^GREEN%^ which further envelopes a %^BOLD%^%^BLACK%^vo%^WHITE%^i%^BLACK%^d%^RESET%^%^GREEN%^. Staring at this mysterious stone further, it suddenly blinks!%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set("intbonus",2);
	set("wisbonus",-2);
	set("chabonus",-1);
	set_heart_beat(1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+"%^RESET%^%^CYAN%^ presses the "+query_short()+"%^RESET%^%^CYAN%^ to the flesh above and between the eyes and wimpers in %^RED%^pain%^CYAN%^ as it slowly sinks half itself beneath the surface of the skin.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You press the "+query_short()+"%^RESET%^%^MAGENTA%^ to your forehead. It slowly, and %^RED%^painfully%^MAGENTA%^, embeds half of its shape under the skin for all to see.%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+"%^RESET%^%^ORANGE%^ inhales with a small amount of %^MAGENTA%^pleasure%^ORANGE%^ as the "+query_short()+"%^RESET%^%^ORANGE%^ is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Warmth%^GREEN%^ and %^MAGENTA%^sensation%^GREEN%^ return to the flesh of your forehead as you pry the "+query_short()+"%^RESET%^%^GREEN%^ out.%^RESET%^");
	ETO->set_property("magic resistance",-10);
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
	 if(random(500) > 495) 
	 {
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "%^RESET%^%^MAGENTA%^The "+query_short()+" %^RESET%^%^MAGENTA%^seems to swivel on your forehead, as if peering about.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^GREEN%^The "+query_short()+" %^RESET%^%^GREEN%^upon "+ETOQCN+"'s %^RESET%^%^GREEN%^forehead turns to regard you.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A piercing %^WHITE%^chill%^CYAN%^ spreads from the "+query_short()+"%^BOLD%^%^CYAN%^ on your forehead. Oddly enough, it seems to %^RESET%^%^MAGENTA%^comfort %^BOLD%^%^CYAN%^you.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^WHITE%^"+ETOQCN+"'s%^BOLD%^%^WHITE%^ breath suddenly %^CYAN%^freezes %^WHITE%^in the air as "+ETO->QS+" breathes out, a sense of relaxation "+ETO->QP+" only response.%^RESET%^", ({ETO}));
				break;
		}
	}
}
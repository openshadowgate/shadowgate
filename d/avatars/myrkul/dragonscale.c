#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^c%^BOLD%^h%^WHITE%^r%^MAGENTA%^o%^RED%^m%^YELLOW%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c %^BOLD%^%^BLACK%^scale%^RESET%^");
	set_id(({ "scale", "armor", "dragon scale armor", "dragon armor", "hide" }));
	set_short("%^RESET%^%^CYAN%^c%^BOLD%^h%^WHITE%^r%^MAGENTA%^o%^RED%^m%^YELLOW%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c %^BOLD%^%^BLACK%^d%^RESET%^r%^BOLD%^%^BLACK%^agon s%^RESET%^c%^BOLD%^%^BLACK%^ale %^RESET%^%^MAGENTA%^a%^BOLD%^r%^RESET%^%^MAGENTA%^m%^BOLD%^o%^RESET%^%^MAGENTA%^r%^RESET%^ ");
	set_obvious_short("%^RESET%^%^CYAN%^c%^BOLD%^h%^WHITE%^r%^MAGENTA%^o%^RED%^m%^YELLOW%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c %^BOLD%^%^BLACK%^d%^RESET%^r%^BOLD%^%^BLACK%^agon s%^RESET%^c%^BOLD%^%^BLACK%^ale %^RESET%^%^MAGENTA%^a%^BOLD%^r%^RESET%^%^MAGENTA%^m%^BOLD%^o%^RESET%^%^MAGENTA%^r%^RESET%^ ");
	set_long("%^YELLOW%^This armor has been made from the hides of many %^RESET%^%^ORANGE%^dragons:%^BOLD%^%^BLACK%^ black, %^GREEN%^green, %^WHITE%^white, %^RED%^red, %^BLUE%^blue%^YELLOW%^, and even a %^RESET%^%^"
	"MAGENTA%^d%^BOLD%^e%^RESET%^%^MAGENTA%^e%^BOLD%^p %^RESET%^%^MAGENTA%^d%^BOLD%^r%^RESET%^%^MAGENTA%^a%^BOLD%^g%^RESET%^%^MAGENTA%^o%^BOLD%^n%^YELLOW%^. The hides are all of %^RESET%^%^CYAN%^c%^BOLD%^h"
	"%^WHITE%^r%^MAGENTA%^o%^RED%^m%^YELLOW%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c%^YELLOW%^ dragons, and the scales are as hard as %^WHITE%^diamond%^YELLOW%^ yet as light as feathers."
	" Each hide would be worth a kings ransom on its own. The hides are layered to provide easy movement with maximum protection. Straps and buckles on the sides provide can adjust the armor to comfort. It"
	" virtually glows with %^BLUE%^magic.%^RESET%^
"
	);
	set_value(20000);
	set_lore("%^YELLOW%^The hides for this armor were %^RED%^skinned%^YELLOW%^ by the famous %^RED%^Malarite%^YELLOW%^ named %^GREEN%^Verin%^YELLOW%^. He hunted down dragons until he could make this armor, which wa"
	"s fashioned for him by a mighty %^RESET%^%^MAGENTA%^cleric %^YELLOW%^of %^RESET%^%^ORANGE%^Malar.%^YELLOW%^ The armor itself is both a boast and a tribute to the lord of the hunt himself.%^RESET%^
"
	);
    set_property("lore difficulty",10);
    set("conbonus",1);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",6);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You feel ready for the %^RED%^hunt!%^RESET%^");
	ETO->add_skill_bonus("survival",2);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You feel disappointed when you remove the "+query_short()+". The %^RED%^hunt%^YELLOW%^ is over.%^RESET%^");
	ETO->add_skill_bonus("survival",-2);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^YELLOW%^"+who->QCN+" strikes at "+ETOQCN+" %^YELLOW%^but the %^RED%^blow%^YELLOW%^ glance off the "+query_short()+"!!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^You feel a %^RED%^blow%^YELLOW%^ glance off your "+query_short()+"!!%^RESET%^");
	tell_object(who,"%^YELLOW%^Your %^RED%^blow%^YELLOW%^ glances off the "+query_short()+"%^YELLOW%^ worn by "+ETOQCN+"!!%^RESET%^");
return (damage*50)/100;	}

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
				tell_object(ETO, "%^YELLOW%^You feel the %^RED%^bloodlust%^YELLOW%^ of %^RED%^Malar%^YELLOW%^ come over you, and underneath the "+query_short()+", %^YELLOW%^your %^RED%^heart%^YELLOW%^ is pounding.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" %^BOLD%^%^RED%^looks positively %^GREEN%^feral%^RED%^!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, ""+query_short()+" %^YELLOW%^positively glitters with %^BLUE%^magic.%^RESET%^");
				tell_room(EETO, ""+query_short()+" %^YELLOW%^worn by "+ETOQCN+" %^YELLOW%^positively glitters with %^BLUE%^magic.%^RESET%^", ({ETO}));
				break;
		}
	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Tombhammer");
	set_id(({ "hammer", "tombhammer", "tomb hammer" }));
	set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^mbh%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^mm%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^");
	set_obvious_short("%^RESET%^A massive %^BOLD%^%^BLACK%^stone %^RESET%^hammer covered in %^RED%^runes%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Your gaze falls over an ancient stone hammer nearly five feet in length. Although it is massive it has very little weight which is odd because the entire hammer is carved from stone. The haft of the hammer is three feet in length and requires two hands for a person to hold it, wrapped in what appears to be ancient %^RESET%^bandages%^BOLD%^%^BLACK%^ of unknown orgin that hang loosely at the end and trail in the air. The head of the hammer is a heavy stone carved to resemble an obelisk sharp and pointed at one end while the other is flat and square. Along the head many darkly %^RESET%^%^RED%^glowing%^ORANGE%^ runes%^BOLD%^%^BLACK%^ have been etched of many many names in all languages.%^RESET%^ 

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^You think you can make out your name in the runes on the hammers head!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(15);
	set_value(10000);
	set_lore(
@AVATAR
According to legend the head of this hammer was taken from the tomb vault of a Pharaoh. It was rumored to have been weileded by some of the most cold blooded warlords for a time. One tale in particular stands out that of Mortin the Scarred. He was reknowned for his cruelty to his enemies and buried them alive till one day while gloating over them all he read the hammer and saw his name on it and all of his enemies rose up to kill him and pulled him into a mass grave while he held this hammer.

AVATAR
	);
	set_property("lore difficulty",20);
	set_heart_beat(1);
	set_type("bludgeoning");
	set_prof_type("hammer");
	set_size(large);
	set_wc(3,8);
	set_large_wc(3,8);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^BLUE%^shivers for a moment as they grasp the %^BOLD%^%^BLACK%^hammer%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BLUE%^The chill of the %^BOLD%^%^BLACK%^grave%^RESET%^%^BLUE%^ sweeps over you%^RESET%^");
	ETO->add_attack_bonus(3);
	ETO->add_damage_bonus(2);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^RED%^seems reluctant to let go of the hammer%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The bandages of the hammer %^RESET%^%^MAGENTA%^caress%^BOLD%^%^BLACK%^ you as you release it%^RESET%^");
	ETO->add_attack_bonus(-3);
	ETO->add_damage_bonus(-2);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 450){
	tell_room(environment(query_wielded()),"%^BOLD%^You feel an agonizing %^RED%^pain%^WHITE%^ in your %^RESET%^soul%^BOLD%^ as the light tries to consume you!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The runes on the %^BLACK%^hammer%^RED%^ explode into %^WHITE%^light%^RED%^ as it strikes "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^You feel an agonizing %^RED%^pain%^WHITE%^ in your %^RESET%^soul%^BOLD%^ as the light tries to consume you!%^RESET%^");
		return roll_dice(5,2)+1;	}

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
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^BLACK%^You hear the whispers of the %^BLUE%^dead%^BLACK%^ all around you.%^RESET%^");
				tell_room(EETO, "", ({ETO}));
				break;
		}
	}
}
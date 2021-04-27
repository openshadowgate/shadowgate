#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("evoker's fist");
	set_id(({ "knuckles", "electrum knuckles", "fist", "evoker's fist" }));
	set_short("%^YELLOW%^E%^RESET%^%^ORANGE%^v%^WHITE%^o%^BOLD%^k%^RESET%^%^ORANGE%^e%^BOLD%^r's F%^WHITE%^i%^RESET%^%^ORANGE%^s%^BOLD%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a set of %^BOLD%^c%^WHITE%^h%^ORANGE%^a%^WHITE%^r%^ORANGE%^g%^WHITE%^e%^ORANGE%^d %^RESET%^%^ORANGE%^e%^BOLD%^l%^BLACK%^e%^ORANGE%^ct%^BLACK%^r%^ORANGE%^u%^RESET%^%^ORANGE%^m k%^BOLD%^n%^RESET%^%^ORANGE%^u%^BOLD%^c%^RESET%^%^ORANGE%^k%^BOLD%^%^WHITE%^l%^ORANGE%^e%^RESET%^%^ORANGE%^s%^WHITE%^");
	set_long("%^RESET%^%^ORANGE%^The distinct smell of %^BOLD%^ozone %^RESET%^%^ORANGE%^surrounds this menacing set of e%^BOLD%^l%^BLACK%^e%^ORANGE%^ct%^BLACK%^r%^ORANGE%^u%^RESET%^%^ORANGE%^m k%^BOLD%^n%^RESET%^%^"
	"ORANGE%^u%^BOLD%^c%^RESET%^%^ORANGE%^k%^BOLD%^%^WHITE%^l%^ORANGE%^e%^RESET%^%^ORANGE%^s, much of its once g%^BOLD%^%^WHITE%^l%^ORANGE%^i%^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^t%^ORANGE%^e%^RESET%^%^ORAN"
	"GE%^n%^BOLD%^i%^WHITE%^n%^RESET%^%^ORANGE%^g surface now %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^rk%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%"
	"^s%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^o%^RED%^r%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^h%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^. Four short, triangular %^BOLD%^%^BLACK%^s%^WHITE%^p%^BLACK%^ik%^"
	"WHITE%^e%^BLACK%^s %^RESET%^%^ORANGE%^protrude out from the metal rings, and into each a single %^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^r%^BOLD%^ca%^RESET%^%^GREEN%^n%^BOLD%^e r%^RESET%^%^GREEN%^u%^BOLD%^"
	"ne %^RESET%^%^ORANGE%^has been etched, %^BOLD%^%^WHITE%^flashing %^RESET%^%^ORANGE%^brightly at random. The air around the weapon seems charged with a %^WHITE%^p%^YELLOW%^r%^RESET%^i%^YELLOW%^ck%^WHIT"
	"E%^l%^RESET%^y %^ORANGE%^energy, and arcing %^BOLD%^e%^WHITE%^l%^ORANGE%^e%^WHITE%^c%^ORANGE%^t%^WHITE%^r%^ORANGE%^i%^WHITE%^c%^ORANGE%^i%^WHITE%^t%^ORANGE%^y %^RESET%^%^ORANGE%^jumps between the spik"
	"es with loud %^BOLD%^c%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^ORANGE%^k%^RESET%^%^ORANGE%^l%^BOLD%^%^RED%^e%^ORANGE%^s%^RESET%^%^ORANGE%^.%^WHITE%^

"	);
	set_value(30000);
	set_lore("%^ORANGE%^This set of knuckles was developed by a wandering warrior-mage known only as %^BOLD%^%^RED%^Krael the Implacable%^RESET%^%^ORANGE%^. Known for his obstinate attitude and apparent inability t"
	"o turn down a challenge, Krael faced the most difficult dare of his life when he was tasked to ascend a perilous mountain peak in the midst of a raging hurricane, and defeat a mighty opponent atop it:"
	" a chosen of %^BOLD%^Talos %^RESET%^%^ORANGE%^named %^BOLD%^%^BLACK%^Zerilas Pakk%^RESET%^%^ORANGE%^, blessed with divine strength and rumored to be immortal. Krael imbued his most powerful magic into"
	" this weapon to make his ascent easier, and to better penetrate the Talossian's unassailable fortitude. Nobody knows how this story ended, or if Krael was victorious, and though a great lightning stor"
	"m is said to have erupted over the mountain peak that night, there have been no reports of either combatant ever being seen again.%^WHITE%^
"	);
	set_property("lore difficulty",30);
	set_item_bonus("sight bonus",3);
	set_item_bonus("spell penetration",25);
	set_item_bonus("endurance",4);
	set_heart_beat(1);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" grips the %^BOLD%^e%^BLACK%^l%^RESET%^e%^YELLOW%^c%^WHITE%^t%^RESET%^r%^BOLD%^%^BLACK%^u%^ORANGE%^m k%^RESET%^%^ORANGE%^n%^BOLD%^u%^RESET%^%^ORANGE%^c%^BOLD%^k%^WHITE%^l%^RESET%^%^ORANGE%^e%^BOLD%^s %^RESET%^%^ORANGE%^tightly, and a %^BOLD%^%^WHITE%^storm %^RESET%^%^ORANGE%^of %^BOLD%^l%^WHITE%^i%^RESET%^g%^YELLOW%^h%^WHITE%^t%^RESET%^n%^YELLOW%^i%^WHITE%^n%^ORANGE%^g %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^c%^BLACK%^h%^ORANGE%^a%^WHITE%^o%^RED%^s %^RESET%^%^ORANGE%^erupts around his fist!%^WHITE%^",ETO);
	tell_object(ETO,"%^ORANGE%^Your grip tightens around the set of %^BOLD%^e%^BLACK%^l%^RESET%^e%^YELLOW%^c%^WHITE%^t%^RESET%^r%^BOLD%^%^BLACK%^u%^ORANGE%^m k%^RESET%^%^ORANGE%^n%^BOLD%^u%^RESET%^%^ORANGE%^c%^BOLD%^k%^WHITE%^l%^RESET%^%^ORANGE%^e%^BOLD%^s%^RESET%^%^ORANGE%^. A %^BOLD%^%^WHITE%^storm %^RESET%^%^ORANGE%^of %^BOLD%^l%^WHITE%^i%^RESET%^g%^YELLOW%^h%^WHITE%^t%^RESET%^n%^YELLOW%^i%^WHITE%^n%^ORANGE%^g %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^c%^BLACK%^h%^ORANGE%^a%^WHITE%^o%^RED%^s %^RESET%^%^ORANGE%^erupts around your fist!%^WHITE%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+"'s grip on the knuckles slackens, and the %^BOLD%^%^WHITE%^storm %^RESET%^%^ORANGE%^of %^BOLD%^e%^RESET%^l%^YELLOW%^e%^RESET%^c%^YELLOW%^t%^RESET%^r%^YELLOW%^i%^RESET%^c%^YELLOW%^i%^RESET%^t%^YELLOW%^y %^RESET%^%^ORANGE%^around his fist %^WHITE%^c%^BOLD%^r%^RESET%^a%^BOLD%^c%^RESET%^k%^BOLD%^%^BLACK%^l%^WHITE%^e%^RESET%^s %^ORANGE%^loudly before dying down.%^WHITE%^",ETO);
	tell_object(ETO,"%^ORANGE%^Your grip on the knuckles slackening, the %^BOLD%^%^WHITE%^storm %^RESET%^%^ORANGE%^of %^BOLD%^e%^RESET%^l%^YELLOW%^e%^RESET%^c%^YELLOW%^t%^RESET%^r%^YELLOW%^i%^RESET%^c%^YELLOW%^i%^RESET%^t%^YELLOW%^y %^RESET%^c%^BOLD%^r%^RESET%^a%^BOLD%^c%^RESET%^k%^BOLD%^%^BLACK%^l%^WHITE%^e%^RESET%^s %^ORANGE%^loudly before dying down.%^WHITE%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+"'s knuckles connect squarely with "+targ->QCN+", delivering a thunderous %^RED%^B%^ORANGE%^O%^BLACK%^O%^RED%^M %^ORANGE%^that leaves "+targ->QCN+" %^RESET%^%^YELLOW%^staggering!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^Your knuckles connect squarely, delivering a thunderous %^RED%^B%^ORANGE%^O%^BLACK%^O%^RED%^M %^ORANGE%^that leaves "+targ->QCN+" %^RESET%^%^YELLOW%^staggering!%^RESET%^");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+"'s knuckles connect squarely with you, delivering a thunderous %^RED%^B%^ORANGE%^O%^BLACK%^O%^RED%^M %^ORANGE%^that leaves you disoriented!%^RESET%^");
		targ->set_paralyzed(roll_dice(8,4)+0);
return 0;	}

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
				tell_object(ETO, "%^YELLOW%^A %^RED%^cacophony %^ORANGE%^of c%^RESET%^r%^YELLOW%^a%^WHITE%^c%^ORANGE%^k%^RESET%^l%^YELLOW%^i%^WHITE%^n%^ORANGE%^g l%^WHITE%^ig%^ORANGE%^h%^WHITE%^t%^ORANGE%^n%^WHITE%^in%^ORANGE%^g erupts around your fist!%^RESET%^");
				tell_room(EETO, "%^YELLOW%^A %^RED%^cacophony %^ORANGE%^of c%^RESET%^r%^YELLOW%^a%^WHITE%^c%^ORANGE%^k%^RESET%^l%^YELLOW%^i%^WHITE%^n%^ORANGE%^g l%^WHITE%^ig%^ORANGE%^h%^WHITE%^t%^ORANGE%^n%^WHITE%^in%^ORANGE%^g erupts around "+ETOQCN+"'s fist!%^RESET%^", ({ETO}));
				break;
		}
	}
}
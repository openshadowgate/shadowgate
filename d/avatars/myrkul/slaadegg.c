#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^s%^BOLD%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^n%^BOLD%^g %^GREEN%^i%^RESET%^%^ORANGE%^n%^GREEN%^f%^BOLD%^e%^RESET%^%^ORANGE%^s%^GREEN%^t%^BOLD%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^t%^RESET%^u%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^r-l%^RESET%^i%^BOLD%^%^BLACK%^k%^RESET%^e%^RESET%^%^GREEN%^ g%^RESET%^%^MAGENTA%^r%^GREEN%^ow%^MAGENTA%^t%^GREEN%^h%^RESET%^");
        set_id(({ "wound", "egg", "tumor", "growth", "infestation" }));
	set_short("%^BOLD%^%^RED%^s%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^a%^BOLD%^d %^WHITE%^egg %^BOLD%^%^GREEN%^i%^RESET%^%^ORANGE%^n%^GREEN%^f%^BOLD%^e%^RESET%^%^ORANGE%^s%^GREEN%^t%^BOLD%^a%^RESET%^%^ORANGE%^t%^GREEN%^i%^BOLD%^o%^RESET%^%^ORANGE%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^s%^BOLD%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^n%^BOLD%^g %^GREEN%^i%^RESET%^%^ORANGE%^n%^GREEN%^f%^BOLD%^e%^RESET%^%^ORANGE%^s%^GREEN%^t%^BOLD%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^t%^RESET%^u%^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^r-l%^RESET%^i%^BOLD%^%^BLACK%^k%^RESET%^e%^RESET%^%^GREEN%^ g%^RESET%^%^MAGENTA%^r%^GREEN%^ow%^MAGENTA%^t%^GREEN%^h%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^You look down in %^RED%^h%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^r%^BOLD%^o%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ at your chest -- something is %^GREEN%^growing%^BLACK%^ there!! The lump is the size of an %^YELLOW%^ostrich egg%^BLACK%^ and it seems to %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^s%^BOLD%^a%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ and move as you look at it!! There is an unpleasant %^RESET%^%^GREEN%^smell%^BOLD%^%^BLACK%^ like some ki

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
The Slaad are creatures from the Plane of Limbo. They implant eggs in the bodies of hosts to carry them. These Slaad eggs kill their host when they hatch. It is nearly impossible to remove a Slaad egg, and only the most skillful of healers can manage such a feat. Being infested with such an egg is nearly always a death sentence.

AVATAR
	);
	set_property("lore difficulty",20);
	set("conbonus",-1);
	set_heart_beat(1);
        set_type("ring");
        set_limbs(({"head"}));
	set_property("enchantment",-1);
  set_property("no remove",1);
	set_ac(1);
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
				tell_object(ETO, "%^BOLD%^%^RED%^You are %^RESET%^%^MAGENTA%^wracked%^BOLD%^%^RED%^ with excruciating %^RESET%^%^RED%^p%^MAGENTA%^a%^RED%^in%^BOLD%^ by the %^BLACK%^growth%^RED%^ in your chest!!%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" %^BOLD%^%^RED%^nearly collapses to the ground, clutching at%^RESET%^ "+query_short()+"%^BOLD%^%^RED%^!!!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^MAGENTA%^You look in %^RED%^horror%^MAGENTA%^ at %^RESET%^"+query_short()+" %^BOLD%^%^MAGENTA%^which seems to %^BLACK%^writhe%^MAGENTA%^ in your chest!%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" %^BOLD%^%^MAGENTA%^looks in %^RED%^horror%^MAGENTA%^ at %^RESET%^"+query_short()+" %^BOLD%^%^MAGENTA%^which seems to %^BLACK%^writhe%^MAGENTA%^ in "+ETO->QP+" chest!%^RESET%^", ({ETO}));
				break;
		}
	}
}

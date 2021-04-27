#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("peacock mask");
	set_id(({ "emotionless mask", "mask", "peacock mask" }));
	set_short("%^GREEN%^em%^ORANGE%^o%^GREEN%^ti%^ORANGE%^o%^GREEN%^nl%^ORANGE%^e%^GREEN%^ss p%^ORANGE%^o%^GREEN%^r%^ORANGE%^c%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^l%^GREEN%^a%^BOLD%^i%^RESET%^%^GREEN%^n m%^ORANGE%^a%^GREEN%^sk%^RESET%^");
	set_obvious_short("%^GREEN%^em%^ORANGE%^o%^GREEN%^ti%^ORANGE%^o%^GREEN%^nl%^ORANGE%^e%^GREEN%^ss p%^ORANGE%^o%^GREEN%^r%^ORANGE%^c%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^l%^GREEN%^a%^BOLD%^i%^RESET%^%^GREEN%^n m%^ORANGE%^a%^GREEN%^sk%^RESET%^");
	set_long("%^GREEN%^The full faced p%^BOLD%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^e%^YELLOW%^l%^RESET%^%^ORANGE%^a%^GREEN%^i%^BOLD%^n mask %^RESET%^%^GREEN%^offers no hint of emotion to those "
	"viewing its simple beauty. Tiny %^WHITE%^e%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^d%^WHITE%^s %^GREEN%^hold in place the vivid p%^BOLD%^e%^RESET%^%^"
	"CYAN%^a%^BOLD%^c%^RESET%^%^GREEN%^c%^BOLD%^o%^RESET%^%^GREEN%^k feathers that line the top of the mask, creating a %^CYAN%^dazzling effect. %^GREEN%^The eyes of the mask have been left bare, allowing "
	"the wearer's own gaze to take the spotlight. On the left cheek, just below the eye is a small brown %^ORANGE%^s%^GREEN%^o%^ORANGE%^n%^GREEN%^g%^ORANGE%^b%^GREEN%^i%^ORANGE%^rd%^GREEN%^. A slit is cut "
	"into the mouth to allow natural speech.%^RESET%^
"	);
	set_value(4000);
	set_lore("%^RESET%^%^GREEN%^It is said that females of some tribes wear masks such as this to stand out among the other woman in the bonding rituals where a mate may choose her. This is all just speculation, it"
	" is pretty afterall, and sometimes that's enough.
"	);
	set_property("lore difficulty",5);
	set_item_bonus("magic resistance",1);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^All trace of emotion leaves "+ETOQCN+" as the "+query_short()+" %^GREEN%^is worn%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^The mask hugs your face protectively%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^A look of insecurity crosses "+ETOQCN+"'s features as the "+query_short()+" %^GREEN%^Is removed%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel less secure with hiding your emotions%^RESET%^");
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
				tell_object(ETO, "%^RESET%^%^GREEN%^You feel good in knowing your feelings are safely hidden behind a "+query_short()+"%^RESET%^");
				tell_room(EETO, "%^RESET%^%^GREEN%^"+ETOQCN+"'s eyes shine brightly through a "+query_short()+"%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^RESET%^%^GREEN%^Your mask seems to repel the magic around you.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^GREEN%^The "+query_short()+" %^GREEN%^hugs "+ETOQCN+"'s face protectively.%^RESET%^", ({ETO}));
				break;
		}
	}
}
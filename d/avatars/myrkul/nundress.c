#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("dress");
	set_id(({ "dress", "robe", "robes" }));
	set_short("%^RESET%^%^RED%^s%^ORANGE%^o%^RED%^m%^ORANGE%^b%^RED%^e%^ORANGE%^r%^RED%^ r%^BOLD%^e%^RESET%^%^RED%^d%^ORANGE%^ c%^YELLOW%^l%^RESET%^%^ORANGE%^erics %^RED%^d%^BOLD%^r%^RESET%^%^RED%^ess%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^s%^ORANGE%^o%^RED%^m%^ORANGE%^b%^RED%^e%^ORANGE%^r%^RED%^ r%^BOLD%^e%^RESET%^%^RED%^d%^ORANGE%^ c%^YELLOW%^l%^RESET%^%^ORANGE%^erics %^RED%^d%^BOLD%^r%^RESET%^%^RED%^ess%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is a %^YELLOW%^conservative%^RESET%^%^ORANGE%^ ankle-length %^CYAN%^c%^BOLD%^l%^RESET%^%^CYAN%^erics%^RED%^ d%^BOLD%^r%^RESET%^%^RED%^ess%^RESET%^%^ORANGE%^ with a round, unrev"
	"ealing neckline and long sleeves. The dress is made of %^WHITE%^cotton%^ORANGE%^ with a %^RED%^d%^BOLD%^%^RED%^e%^RESET%^%^RED%^ep r%^BOLD%^e%^RESET%^%^RED%^d h%^BOLD%^u%^RESET%^%^RED%^e%^ORANGE%^. Th"
	"e skirt is flat without pleats or other embellishments. A sash or cord might compliment the waist but this is left to the wearer to determine the best accessory. Overall the dress is %^BOLD%^%^GREEN%^"
	"well-made%^RESET%^%^ORANGE%^ and %^BOLD%^%^GREEN%^attractive%^RESET%^%^ORANGE%^. %^YELLOW%^It is made for a woman of the cloth or other high official who takes herself seriously and expects others to "
	"as well. %^RESET%^
"
	);
	set_value(5000);
	set_lore("%^YELLOW%^Lora of Lathander was a famous leader of the %^RESET%^%^RED%^D%^BOLD%^a%^RESET%^%^RED%^wnf%^BOLD%^i%^RESET%^%^RED%^re A%^BOLD%^b%^RESET%^%^RED%^bey%^YELLOW%^ near the %^GREEN%^upper Meadow L"
	"ands%^YELLOW%^ that withstood pestilence and invasion of orcs in 600 SG. She wore a dress of this type, as did every Abbess to follow her. It is unknown if any of these dresses are the original, but a"
	"ll hold power that is more than just a symbol of the %^RESET%^%^ORANGE%^S%^YELLOW%^u%^RESET%^%^ORANGE%^n G%^YELLOW%^o%^RESET%^%^ORANGE%^d%^YELLOW%^.%^RESET%^ 
"
	);
    set_property("lore difficulty",10);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",2);
	set_item_bonus("healing",2);
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_object(ETO,"%^YELLOW%^You feel the %^WHITE%^power%^YELLOW%^ wash over you as you wear "+query_short()+"%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^YELLOW%^The feeling of %^RED%^Lathanders%^YELLOW%^ leaves you as you remove "+query_short()+".%^RESET%^");
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
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, "%^YELLOW%^You feel the %^RED%^faith%^YELLOW%^ of Lathander wash over you.%^RESET%^");
				tell_room(EETO, ""+query_short()+" worn by "+ETOQCN+" seems to %^YELLOW%^shimmer.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, ""+query_short()+" %^YELLOW%^glows a deep %^RED%^red.%^RESET%^");
				tell_room(EETO, ""+query_short()+" worn by "+ETOQCN+" %^YELLOW%^glows a deep %^RED%^red.%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "");
				tell_room(EETO, "yes", ({ETO}));
				break;
		}
	}
}
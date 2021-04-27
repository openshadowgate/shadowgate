#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Armband of the Tumultous Mind");
	set_id(({ "armband", "arm", "armband of the tumultous mind", "tumultous mind", "lightning armband" }));
	set_short("%^BOLD%^%^CYAN%^Arm%^WHITE%^b%^CYAN%^and of the %^BOLD%^%^BLUE%^T%^MAGENTA%^u%^YELLOW%^m%^BLUE%^u%^MAGENTA%^l%^YELLOW%^t%^BLUE%^o%^MAGENTA%^u%^YELLOW%^s %^GREEN%^M%^BOLD%^%^BLUE%^i%^GREEN%^nd%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^ligh%^WHITE%^t%^YELLOW%^ning %^GREEN%^b%^BLUE%^o%^GREEN%^lt %^CYAN%^arm%^MAGENTA%^b%^CYAN%^and%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This armband is a rather intricate and delicate piece of artistry. The metal used is %^CYAN%^pure%^YELLOW%^ and %^RESET%^polished %^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^lv%^CYAN%^e%^WHITE%^r%^YELLOW%^. The method used to create a %^RESET%^%^RED%^ch%^BOLD%^%^BLUE%^ao%^RESET%^%^RED%^tic%^BOLD%^%^YELLOW%^ pattern of a lighting bolt has almost been lost to time. The %^WHITE%^s%^CYAN%^i%^WHITE%^lv%^CYAN%^e%^WHITE%^r %^YELLOW%^has been heated to almost liquidity and pulled %^RESET%^%^MAGENTA%^violently%^BOLD%^%^YELLOW%^ while high powered billows are blown upon it. At first glance appearing as a ruined cage, a skilled eye can see the beauty of the bolt's existence within. The smell of %^RESET%^%^GREEN%^oz%^BLUE%^o%^GREEN%^ne%^BOLD%^%^YELLOW%^ lingers about the metal.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(35000);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^The method used to create such artistry has been lost to the ages, but not because of the method but because what must be used in the method. In order to properly heat the metal to keep it's polished nature, a lightning elemental must be summoned and convinced to work with the smith in order to heat the metal. In the process of the heating and shaping, the elemental is then slain and infused within the metal, it's mind and body forever imprinted in the metal.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",35);
	set("conbonus",-1);
	set("dexbonus",1);
	set_heart_beat(1);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+"%^BOLD%^%^CYAN%^ stiffens suddenly and soon relaxes as the ends of "+ETOQCN+"%^BOLD%^%^CYAN%^'s armband turn viciously inward and imbed into "+ETOQCN+"%^BOLD%^%^CYAN%^'s skin.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The ends of the armbands bolts turn viciously inward and imbed into the skin of your arm, you feel a chaotic mind settle close to yours.%^RESET%^");
	ETO->do_damage("torso",random(5));
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+"%^BOLD%^%^WHITE%^ easilly twist the "+query_short()+"%^BOLD%^%^WHITE%^ off of her arm.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The ends of the armband silkily recede from your arm as you twist it off of you.%^RESET%^");
	ETO->set_property("magic resistance",-5);
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
				tell_object(ETO, "%^BOLD%^%^YELLOW%^Arcs of electricity can be seen sliding across the "+ETOQCN+"%^BOLD%^%^YELLOW%^ causing the hair on your arm to raise.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^YELLOW%^Arcs of electricity can be seen sliding across "+ETOQCN+"%^BOLD%^%^YELLOW%^'s "+query_short()+"%^BOLD%^%^YELLOW%^ causing "+ETO->QP+"%^BOLD%^%^YELLOW%^ to quiver slightly.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^BLUE%^The scent of %^RESET%^%^GREEN%^oz%^BLUE%^o%^GREEN%^ne %^BOLD%^%^BLUE%^rises off of your armband.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^BLUE%^The scent of %^RESET%^%^GREEN%^oz%^BLUE%^o%^GREEN%^ne %^BOLD%^%^BLUE%^ emanates from "+ETOQCN+"%^BOLD%^%^BLUE%^.%^RESET%^", ({ETO}));
				break;
		}
	}
}
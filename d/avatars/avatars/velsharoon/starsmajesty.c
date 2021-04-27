#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^Sword of %^BOLD%^%^YELLOW%^St%^RED%^a%^YELLOW%^rs %^CYAN%^Maj%^WHITE%^e%^CYAN%^sty%^RESET%^");
	set_id(({ "sword", "longsword", "long sword", "star sword" }));
	set_short("%^BOLD%^%^BLUE%^Sword of %^BOLD%^%^YELLOW%^St%^RED%^a%^YELLOW%^rs %^CYAN%^Maj%^WHITE%^e%^CYAN%^sty%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^sh%^RESET%^i%^BLUE%^mm%^RESET%^e%^BLUE%^r%^RESET%^i%^BLUE%^ng %^BOLD%^%^BLUE%^long sword%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This long sword seems to be almost weightless. The blade itself is composed of some %^BOLD%^%^BLACK%^dark %^BLUE%^material and tiny pinpricks %^RESET%^%^BLUE%^sh%^RESET%^i%^BLUE%^mm%^R"
	"ESET%^e%^BLUE%^r%^BOLD%^ within it's depths. The pommel and hilt are of simple construction but forged of %^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l%^BLUE%^. Strips of dark %^RESET%^%^BLUE%^bl"
	"ue%^BOLD%^ felt are tightly wrapped around the handle and provide a very comfortable grip.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^BLUE%^Star's themselves sometimes die, and when they do, particles of them must plunge to the earth and embed themselves into our soul. When found, the ore that is produced is very fragile but seems"
	" to retain a bit of the star's luster. Properly melted down and mixed with only mithril, the alloy darkens to near blackness with tiny pinpricks shifting in and out of light upon it's surface. This hi"
	"ghly prized metal, starnium, is almost weightless but when forged into weapons retains the weapons' deadliness. When used in armor it is nigh inpenetrable. It is speculated that the alloy itself will "
	"assist in absorbing magical energies, although prior to smelting the ore may be enchanted.


%^RESET%^%^GREEN%^-On the Origins of Starnium-
%^RESET%^%^GREEN%^Alethunder Drakewing
"
	);
    set_property("lore difficulty",17);
	set_heart_beat(1);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^The "+query_short()+" %^RESET%^%^MAGENTA%^appears in "+ETOQCN+"'s %^RESET%^%^MAGENTA%^hand!%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^The "+query_short()+" %^RESET%^%^MAGENTA%^appears in your hand!%^RESET%^");
	ETO->set_property("magic resistance",25);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^GREEN%^The "+query_short()+" %^RESET%^%^GREEN%^disappears from "+ETOQCN+"'s %^RESET%^%^GREEN%^hand and is seen in "+ETOQCN+" %^RESET%^%^GREEN%^sheeth!%^RESET%^",ETO);
	tell_object(ETO,"%^GREEN%^The "+query_short()+" %^RESET%^%^GREEN%^disappears from your hand and appears in your sheeth!%^RESET%^");
	ETO->set_property("magic resistance",-25);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^leaps from "+ETOQCN+"'s %^BOLD%^%^CYAN%^hand to cleave into "+targ->QCN+"%^BOLD%^%^CYAN%^ then appears back in "+ETOQCN+" %^BOLD%^%^CYAN%^hand!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^leaps from your hand and cleaves into "+targ->QCN+"%^BOLD%^%^CYAN%^ then appears back in your hand!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^leaps from "+ETOQCN+"'s %^BOLD%^%^CYAN%^hand to cleave into you only to appear back in "+ETOQCN+" %^BOLD%^%^CYAN%^hand!%^RESET%^");
		return roll_dice(3,4)+0;	}

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
				tell_object(ETO, "%^BOLD%^%^BLUE%^The "+query_short()+" %^RESET%^%^BLUE%^sh%^RESET%^i%^BLUE%^mm%^RESET%^e%^BLUE%^rs %^BOLD%^and seems to %^RESET%^%^MAGENTA%^humm%^BOLD%^%^BLUE%^ with power.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+"'s "+query_short()+" %^RESET%^%^BLUE%^sh%^RESET%^i%^BLUE%^mm%^RESET%^e%^BLUE%^rs %^BOLD%^and seems to %^RESET%^%^CYAN%^vibrate%^BOLD%^%^BLUE%^ in "+ETO->QP+" %^BOLD%^%^BLUE%^hand.%^RESET%^", ({ETO}));
				break;
		}
	}
}
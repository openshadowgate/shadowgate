#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "sword" }));
	set_short("%^BOLD%^%^RED%^M%^BLACK%^e%^RED%^t%^YELLOW%^e%^RED%^or Sw%^CYAN%^o%^RED%^rd%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^red colored%^RESET%^ sword");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This sword is blood red from hilt to tip. Hard as %^CYAN%^steel%^RED%^ but with the color of the setting %^YELLOW%^sun%^BOLD%^%^RED%^. It has an oddly light weight to it, and seems to be %^BLACK%^razor%^RED%^ sharp.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1000);
	set("strbonus",1);
	set_heart_beat(1);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",3);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The sword leaps to your hand, ready for %^CYAN%^battle!%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The sword sighs, disappointed, as it leaves your hand...%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+query_short()+" strikes furiously at "+targ->QCN+", leaving %^GREEN%^blood%^RED%^ spattered everywhere!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^"+query_short()+" strikes furiously at "+targ->QCN+", leaving %^GREEN%^blood%^RED%^ spattered everywhere!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+query_short()+" strikes furiously at you, leaving %^GREEN%^blood%^RED%^ spattered everywhere!%^RESET%^");
		return roll_dice(0,0)+0;	}

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
				tell_object(ETO, "The sword %^BOLD%^%^RED%^glows%^RESET%^ faintly...");
				tell_room(EETO, "The sword %^BOLD%^%^RED%^glows%^RESET%^ faintly...", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "The %^BOLD%^%^RED%^sword%^RESET%^ yearns for battle!");
				tell_room(EETO, "", ({ETO}));
				break;
		}
	}
}
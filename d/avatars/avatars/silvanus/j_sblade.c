#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("jagged_blade");
	set_id(({ "sword", "blade", "jagged sword", "jagged blade", "jagged blade of souls", "jagged sword of souls" }));
	set_short("%^BOLD%^%^BLACK%Jagged Blade of %^RESET%^%^RED%^Souls%^RESET%^");
	set_obvious_short("short sword");
	set_long(
@AVATAR
%^RED%^This is a very finely crafted short short, with a horribly %^BLUE%^jagged%^RED%^ blade.  The blade is a %^BOLD%^%^BLACK%^dark grey%^RESET%^%^RED%^ in hue and %^YELLOW%^gleams%^RESET%^%^RED%^ an %^BOLD%^%^BLACK%^abyssal%^RESET%^%^RED%^ black.  The blade connects to the slightly lighter %^BOLD%^%^BLACK%^grey%^RESET%^%^RED%^ hilt by the means of a perfectly crafted yet contrasting %^CYAN%^crystalline%^RESET%^%^RED%^ pommel.%^RESET%^ 

AVATAR
	);
	set_weight(12);
	set_value(100);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,5);
	set_large_wc(1,10);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" grips the hilt of the "+query_short()+" and cries out in pain!%^RESET%^",TP);
	tell_object(TP,"%^RED%^You shriek in pain as you grip the hilt of the "+query_short()+"!%^RESET%^");
	TP->do_damage("torso",random(12));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^RED%^"+TP->query_cap_name()+" releases the "+query_short()+" and cries out in pain!%^RESET%^",TP);
	tell_object(TP,"%^RED%^You shriek in pain as you release the hilt of the "+query_short()+"!%^RESET%^");
	TP->do_damage("torso",random(12));
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+" cackles evilly as the "+query_short()+" slices into "+targ->query_cap_name()+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^You cackle evilly as your "+query_short()+" slices into "+targ->query_cap_name()+"!%^RESET%^");
	tell_object(targ,"%^RED%^"+ETO->query_cap_name()+" cackles evilly as the "+query_short()+" slices into you!%^RESET%^");
		return roll_dice(2,6)+1;	}
}
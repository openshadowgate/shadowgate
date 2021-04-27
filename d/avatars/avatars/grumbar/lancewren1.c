#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lawgiving Lance");
	set_id(({ "lance" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^a sleek and slender lance%^RESET%^");
	set_obvious_short("a heavy lance");
	set_long(
@AVATAR
%^RESET%^This sleek and slender lance is crafted from many small, blue %^BOLD%^%^BLUE%^sapphires%^RESET%^.  The gems have been crushed into a dust and added to the exterior of the lance through some mystical process.  It is easy on the eyes and light when wielded.  Symbols have been etched along the length of the shaft.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^BOLD%^%^BLUE%^With each strike of this weapon...
%^RESET%^%^BOLD%^%^BLUE%^     ...justice will be served%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(3000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(2);
	set_wc(2,100);
	set_large_wc(3,100);
	set_property("enchantment",1);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+"%^RESET%^%^BOLD%^%^BLUE%^ appears to relax visibly as he wields "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^Calm overwhelms you as you wield "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("constitution",1);
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^BOLD%^%^BLUE%^shakes his head slowly, looks confused for a moment, then returns to his normal self%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^Reality returns slowly as you put away "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^BLUE%^Blue sparks fly as "+query_short()+" %^RESET%^%^BOLD%^%^BLUE%^strikes "+targ->QCN+" %^RESET%^%^BOLD%^%^BLUE%^smartly%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^BLUE%^Blue sparks fly as "+query_short()+" %^RESET%^%^BOLD%^%^BLUE%^strikes "+targ->QCN+" %^RESET%^%^BOLD%^%^BLUE%^smartly%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^BLUE%^Visions of peace and calm flood your mind as "+ETOQCN+" %^RESET%^%^BOLD%^%^BLUE%^strikes you smartly with his "+query_short()+"%^RESET%^");
		return roll_dice(10,20)+0;	}
}
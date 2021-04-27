#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lance of the Lawgiver");
	set_id(({ "lance" }));
	set_short("%^RESET%^a %^BOLD%^%^BLACK%^black %^RESET%^and %^BOLD%^%^WHITE%^white %^RESET%^lance");
	set_long(
@AVATAR
%^RESET%^This beautiful, sleek lance is wonderful in it's appearance.  It is crafted from a single piece of %^ORANGE%^ash %^RESET%^and covered in %^BOLD%^%^BLACK%^jet stone %^RESET%^and %^BOLD%^%^WHITE%^pearl%^RESET%^.  It is balanced to perfection and actually feels as light as a feather when held.  There are %^BOLD%^%^CYAN%^symbols %^RESET%^etched along the length of the weapon.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^BOLD%^%^WHITE%^"%^BLUE%^May this weapon..
%^RESET%^%^BOLD%^%^BLUE%^     ...bring justice to the world%^WHITE%^"%^RESET%^

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
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^RED%^A low hum fills the air and then is suddenly gone%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^A soothing vibration runs through your arm as you wield "+query_short()+" then suddenly dissipates%^RESET%^");
	ETO->add_stat_bonus("constitution",1);
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^CYAN%^You notice the sudden silence and then the sound of crickets in the background%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^CYAN%^You feel rejuvinated as you unwield "+query_short()+"%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^RED%^"+ETOQCN+" strikes "+targ->QCN+" smartly with "+query_short()+" and seems comforted somehow%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^You feel justified in your actions as "+targ->QCN+" is struck smartly with "+query_short()+"%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^RED%^You feel comforted as "+ETOQCN+" strikes you smartly with "+query_short()+"%^RESET%^");
		return roll_dice(10,6)+0;	}
}
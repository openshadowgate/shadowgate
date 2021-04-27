#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("auril hammer");
	set_id(({ "hammer" }));
	set_short("%^BOLD%^%^BLUE%^Auril's Hammer%^RESET%^");
	set_obvious_short("A massive blue hammer");
	set_long(
@AVATAR
A massive blue hammer

AVATAR
	);
	set_weight(350);
	set_value(50000000);
	set_property("lore difficulty",100);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(4,20);
	set_large_wc(4,20);
	set_property("enchantment",20);
	set_ac(100);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The ground shakes as "+ETOQCN+" wields the hammer.",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",10);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The ground shakes as "+ETOQCN+" unwields the hammer.",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("strength",-10);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"The hammer crashes into "+targ->QCN+" with devestatingly horrendous terrifying force!",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"");
		return roll_dice(100,20)+0;	}
}
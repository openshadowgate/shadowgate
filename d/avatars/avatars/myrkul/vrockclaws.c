#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^V%^RED%^r%^BLACK%^ock C%^RED%^l%^BLACK%^aws%^RESET%^");
	set_id(({ "claws" }));
	set_short("%^BOLD%^%^BLACK%^V%^RED%^r%^BLACK%^ock C%^RED%^l%^BLACK%^aws%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^V%^RED%^r%^BLACK%^ock C%^RED%^l%^BLACK%^aws%^RESET%^");
	set_long(
@AVATAR
These are long, hideously sharp claws that are grown by the hideous Vrock!

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_type("slashing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" slashes into "+targ->QCN+" visciously!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"You slash into "+targ->QCN+" viciously!!");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" slashes into you viscously!!%^RESET%^");
		return roll_dice(2,10)+0;	}

}

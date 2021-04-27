#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Lichfinger");
	set_id(({ "dagger", "Dagger" }));
	set_short("%^CYAN%^A%^RESET%^ %^BLUE%^lichs%^RESET%^ %^CYAN%^finger on a%^RESET%^ %^YELLOW%^stick%^RESET%^");
	set_obvious_short("%^CYAN%^A%^RESET%^ %^BOLD%^%^WHITE%^skeletal%^RESET%^ %^MAGENTA%^pinky%^RESET%^ %^CYAN%^on a%^RESET%^ %^YELLOW%^stick%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^At a distance, this might look more like a popsicle than a finger on a%^RESET%^ %^YELLOW%^stick%^RESET%^%^CYAN%^. But as its name suggests, it is a finger on a stick. The finger,%^RESET%^ %^BOLD%^%^WHITE%^old%^RESET%^ %^CYAN%^and%^RESET%^ %^RED%^gnarly%^RESET%^ %^CYAN%^radiates a palpable aura of%^RESET%^ %^BOLD%^%^BLACK%^evil%^RESET%^ %^CYAN%^and causes those who behold it to tremble with fear (alternatively, they tremble with%^RESET%^ %^MAGENTA%^laughter.%^RESET%^ %^CYAN%^Its a finger on a stick, afterall). Though not the most practical of weapons, this is perfect when you want to give people%^RESET%^ %^RED%^"THE FINGER!"%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^Up yours!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3 pounds);
	set_value(0);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(small);
	set_wc(10,10);
	set_large_wc(10,20);
	set_property("enchantment",30);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" wields the "+query_short()+" and looks ready to give you the finger%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^You wield "+query_short()+" and look prepared to give people the finger%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1/5){
	tell_room(environment(query_wielded()),"%^CYAN%^"+ETOQCN+" gives "+targ->QCN+"%^RESET%^ %^RED%^THE FINGER%^RESET%^ %^CYAN%^with "+query_short()+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^You give "+targ->QCN+" the finger with "+query_short()+"%^RESET%^");
	tell_object(targ,"%^CYAN%^"+ETOQCN+" gives you%^RESET%^ %^RED%^THE FINGER%^RESET%^ %^CYAN%^with "+query_short()+"%^RESET%^");
		targ->set_paralyzed(roll_dice(2,4)+0);
return 0;	}
}
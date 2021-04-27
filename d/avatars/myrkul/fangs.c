#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^P%^YELLOW%^o%^RESET%^%^CYAN%^is%^YELLOW%^o%^RESET%^%^CYAN%^ned F%^YELLOW%^a%^RESET%^%^CYAN%^ngs%^RESET%^");
	set_id(({ "fangs" }));
	set_short("%^RESET%^%^CYAN%^P%^YELLOW%^o%^RESET%^%^CYAN%^is%^YELLOW%^o%^RESET%^%^CYAN%^ned F%^YELLOW%^a%^RESET%^%^CYAN%^ngs%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^P%^YELLOW%^o%^RESET%^%^CYAN%^is%^YELLOW%^o%^RESET%^%^CYAN%^ned F%^YELLOW%^a%^RESET%^%^CYAN%^ngs%^RESET%^");
	set_long("These are hideous fangs that are dripping with venom.
");
	set_value(0);
	set_property("enchantment",5);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" %^BOLD%^%^RED%^rends "+targ->QCN+" %^BOLD%^%^RED%^to shreds with "+query_short()+"%^BOLD%^%^RED%^ leaving its %^RESET%^%^MAGENTA%^hapless victim%^BOLD%^%^RED%^ writhing in %^BOLD%^%^BLACK%^mortal agony%^BOLD%^%^RED%^ from the %^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^athly v%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^nom!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You strike "+targ->QCN+" with "+query_short()+" leaving your enemy screaming in pain from the horrible venom!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^************************************************************************************************************************************************************************************************** %^BLACK%^YOU FEEL DEATH IS NEAR AS THE POISON ENTERS YOUR VEINS%^RED%^**************************************************************************************************************************************************************************************************%^RESET%^");
		return roll_dice(1,200)+500;	}

}

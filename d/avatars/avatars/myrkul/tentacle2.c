#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("tentacle");
	set_id(({ "tentacle" }));
	set_short("%^BOLD%^%^RED%^f%^RESET%^%^RED%^e%^BOLD%^%^RED%^a%^RESET%^%^RED%^r%^BOLD%^s%^RESET%^%^RED%^o%^BOLD%^m%^RESET%^%^RED%^e %^BOLD%^%^GREEN%^tentacle%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^f%^RESET%^%^RED%^e%^BOLD%^%^RED%^a%^RESET%^%^RED%^r%^BOLD%^s%^RESET%^%^RED%^o%^BOLD%^m%^RESET%^%^RED%^e %^BOLD%^%^GREEN%^tentacle%^RESET%^");
	set_long("You shouldn't see this! It is a plot item for monsters.
");
	set_value(0);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+targ->QCN+" is struck with the %^RESET%^%^MAGENTA%^s%^BOLD%^l%^RESET%^%^MAGENTA%^i%^BOLD%^m%^RESET%^%^MAGENTA%^y%^BOLD%^%^GREEN%^ %^BLUE%^p%^RESET%^%^BLUE%^o%^BOLD%^is%^RESET%^%^BLUE%^o%^BOLD%^no%^RESET%^%^BLUE%^u%^BOLD%^s%^GREEN%^ tentacle!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^You strike "+query_short()+" with the %^RESET%^%^MAGENTA%^slimy%^BOLD%^%^GREEN%^ tentacle!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^You are struck with the %^RESET%^%^MAGENTA%^s%^BOLD%^l%^RESET%^%^MAGENTA%^i%^BOLD%^m%^RESET%^%^MAGENTA%^y%^BOLD%^%^GREEN%^ %^BLUE%^p%^RESET%^%^BLUE%^o%^BOLD%^is%^RESET%^%^BLUE%^o%^BOLD%^no%^RESET%^%^BLUE%^u%^BOLD%^s%^GREEN%^ tentacle!%^RESET%^");
		return roll_dice(1,100)+0;	}

}

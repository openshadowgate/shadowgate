#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("xorrot");
	set_id(({ "rot" }));
	set_short("%^RESET%^%^ORANGE%^Handful of %^MAGENTA%^Beshaba's%^BOLD%^ Crotch Rot%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^G%^RESET%^%^GREEN%^h%^BOLD%^a%^RED%^s%^GREEN%^t%^RESET%^%^GREEN%^l%^BOLD%^y%^MAGENTA%^ Boil Covered%^RESET%^%^ORANGE%^ Handful%^BOLD%^%^MAGENTA%^ of%^BLACK%^ Pestilence%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This seems to be a handful of pure disease filled pestilence. It is ghastly to see, and must be pure death.%^RESET%^
");
	set_value(0);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 750){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" %^RED%^old %^RESET%^%^ORANGE%^lady %^BOLD%^%^MAGENTA%^gropes "+targ->QCN+"%^BOLD%^%^RED%^ with "+query_short()+"%^BOLD%^%^RED%^ in the %^GREEN%^foulest%^RED%^ way imaginable! "+targ->QCN+" %^BOLD%^%^RED%^goes down with a case of hideous %^RESET%^%^MAGENTA%crotch %^BOLD%^rot!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You grope "+targ->QCN+" in the foulest way imaginable!!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" %^RED%^old %^RESET%^%^ORANGE%^lady %^BOLD%^%^MAGENTA%^gropes you%^BOLD%^%^RED%^ with "+query_short()+"%^BOLD%^%^RED%^ in the %^GREEN%^foulest%^RED%^ way imaginable! You%^BOLD%^%^RED%^go down with a case of hideous %^RESET%^%^MAGENTA%crotch %^BOLD%^rot!%^RESET%^");
		return roll_dice(1,200)+0;	}

}

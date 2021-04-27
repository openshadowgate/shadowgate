#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create(){
	::create();
	set_name("hammer");
	set_id(({ "hammer" }));
	set_short("%^YELLOW%^M%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^a%^YELLOW%^d%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^s %^YELLOW%^H%^RESET%^%^ORANGE%^ammer of %^BOLD%^%^WHITE%^Skullcrushing%^RESET%^");
	set_obvious_short("%^YELLOW%^M%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^a%^YELLOW%^d%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^s %^YELLOW%^H%^RESET%^%^ORANGE%^ammer of %^BOLD%^%^WHITE%^Skullcrushing%^RESET%^");
	set_long("This hammer is used for OOC purposes of smacking the crap out of annoying monsters. And occasionally annoying players.
");
	set_value(0);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+" smacks the crap out of "+targ->QCN+" with a "+query_short()+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^You smack the crap out of "+targ->QCN+" with your "+query_short()+"%^RESET%^");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+" smacks the crap out of you with a "+query_short()+"%^RESET%^");
		return roll_dice(1,1)+1000;	}

}

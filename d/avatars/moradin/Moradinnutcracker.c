#include <std.h>
inherit "/d/common/obj/weapon/warhammer";

void create(){
	::create();
	set_name("Nutcracker");
	set_id(({ "nutcracker" }));
	set_short("%^RESET%^%^ORANGE%^Nutcracker of %^BOLD%^%^BLACK%^D%^RESET%^%^WHITE%^oo%^BOLD%^%^BLACK%^m%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Nutcracker of %^BOLD%^%^BLACK%^D%^RESET%^%^WHITE%^oo%^BOLD%^%^BLACK%^m%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is a an oversized nutcracker used to crack the nuts on all those big monsters%^RESET%^
");
	set_value(0);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" wields the "+query_short()+"%^RESET%^%^ORANGE%^, and are ready to crack some nuts!",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You wield the "+query_short()+"%^RESET%^%^ORANGE%^, you are ready to crack some nuts!");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" set the "+query_short()+" aside and stops nutcracking",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You set the hammer aside and stops nutcracking");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1000){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+" dashes in and places the "+query_short()+" %^RESET%^%^ORANGE%^around "+targ->QCN+" %^RESET%^%^ORANGE%^balls and squeezes !",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^You dash in and places the "+query_short()+" %^RESET%^%^ORANGE%^around "+targ->QCN+" %^RESET%^%^ORANGE%^balls and squeezes ! ");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+" dashes in and places the "+query_short()+" %^RESET%^%^ORANGE%^around your %^RESET%^%^ORANGE%^balls and squeezes ! %^BOLD%^%^MAGENTA%^THE PAIN!");
		return roll_dice(1,4)+1000;	}

}

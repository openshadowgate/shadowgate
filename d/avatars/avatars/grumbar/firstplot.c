#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Charge of Bane");
	set_id(({ "sword" }));
	set_short("a dull blue sword");
	set_obvious_short("a sword");
	set_long(
@AVATAR
test

AVATAR
	);
	set("read",
@AVATAR
Only the most deserving can feel the strong arm of the lord Bane

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(2500);
	set("strbonus",1);
	set("chabonus",-1);
	set("conbonus",1);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(3,6);
	set_property("enchantment",5);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^GREEN%^"+ETOQCN+" hits "+targ->QCN+" smartly with his "+query_short()+" causing "+targ->QCN+" to stumble backwards briefly%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^GREEN%^"+query_short()+" hits "+targ->QCN+" smartly, causing them to lose their balance and stumble backwards%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^GREEN%^You feel the deep bite of the "+query_short()+" as "+ETOQCN+" strikes you smartly with it%^RESET%^");
		targ->set_paralyzed(roll_dice(1,4)+0);
return 0;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Bone Shard");
	set_id(({ "dagger" }));
	set_short("a sharp bone shard");
	set_obvious_short("piece of bone");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^WHITE%^This is a short bone shard that is looks razor sharp.  This small piece of bone could eviscerate someone in a split second!%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(150000);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(2);
	set_wc(10,100);
	set_large_wc(20,100);
	set_property("enchantment",5);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" produces a "+query_short()+" magically in his hand",ETO);
	tell_object(ETO,"produces the "+query_short()+"");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"q",ETO);
	tell_object(ETO,"**");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < **){
	tell_room(environment(query_wielded()),"**",({ETO,targ}));
	tell_object(ETO,"**");
	tell_object(targ,"**");
	}
}
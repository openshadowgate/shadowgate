#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("testweap");
	set_id(({ "test" }));
	set_short("test");
	set_long(
@AVATAR
ok1

AVATAR
	);
	set_weight(1);
	set_value(100);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < ){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"");
	tell_object(targ,"");
	}
}
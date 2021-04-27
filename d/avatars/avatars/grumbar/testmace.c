#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("macetest");
	set_id(({ "mace" }));
	set_short("test mace");
	set_obvious_short("pink mace");
	set_long(
@AVATAR
blah blah

AVATAR
	);
	set("read",
@AVATAR
no

AVATAR
	);
     set("langage","common");	set_weight(6);
	set_value(1000);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",8);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+query_short()+" wields the mace",ETO);
	tell_object(ETO,""+query_short()+" wields the mace");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+query_short()+" unwields mace",ETO);
	tell_object(ETO,""+query_short()+" unwields mace");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"eat me!",({ETO,targ}));
	tell_object(ETO,"eat me!");
	tell_object(targ,"eat me!");
		return roll_dice(3,6)+0;	}
}
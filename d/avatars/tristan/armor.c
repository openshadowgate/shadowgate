#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor");
	set_id(({ "armor", "test" }));
	set_short("this is an armor test");
	set_obvious_short("test");
	set_long(
@AVATAR
test
test

AVATAR
	);
	set_weight(5);
	set_value(2);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"4N wears it",TP);
	tell_object(TP,"you wear it");
	return 1;
}
int remove_func(){
	tell_room(ETP,""+TP->query_cap_name()+" removes it",TP);
	tell_object(TP,"you remove it");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 999){
	tell_room(environment(query_wielded()),"$n was hit",({ETO,targ}));
	tell_object(ETO,"you hit "+ETO->query_cap_name()+"");
	tell_object(targ,"you'r hit");
		return (damage*50)/100;
	}}
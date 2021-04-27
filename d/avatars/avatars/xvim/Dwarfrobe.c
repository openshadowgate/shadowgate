#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven robe");
	set_id(({ "robe" }));
	set_short("%^ORANGE%^Dwarven robe");
	set_obvious_short("a old robe");
	set_long(
@AVATAR
This is a robe used by the best dwarven fighters, it is not fancy in any way, but is made out of thick soft fabrics and offer exellent protection.

AVATAR
	);
	set_weight(10);
	set_value(4000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"You wear the "+query_short()+" and feel well protected.");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"You remove the "+query_short()+" and feel the wind touch your skin.");
	TP->set_property("magic resistance",5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 125){
	tell_room(environment(query_worn()),""+query_short()+" protects "+ETO->query_cap_name()+" as "+who->query_cap_name()+" takes a swing at him.",({ETO,who}));
	tell_object(ETO,"The "+query_short()+" protects you as "+who->query_cap_name()+" hits you");
	tell_object(who,"The "+query_short()+" "+ETO->query_cap_name()+" is wearing offers him some protection.");
		return (damage*40)/100;
	}
}

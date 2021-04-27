#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Invisible Plate");
	set_id(({ "plate" }));
	set_short("%^RESET%^%^BLACK%^Invisible Plate%^RESET%^");
	set_obvious_short("%^RESET%^%^BLACK%^invisible plate%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(0);
	set_value(1000000);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",20);
	set_ac(20);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("dexterity",5);
	ETO->set_property("magic resistance",50);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("dexterity",-5);
	ETO->set_property("magic resistance",-50);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),"You know you hit the person you are attacking but the "+query_short()+" deflects your attack well.",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"You know you hit the person you are attacking but the "+query_short()+" deflects your attack well.");
		who->do_damage("torso",random(50));
return damage;	}
}
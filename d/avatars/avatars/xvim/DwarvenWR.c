#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven War Robe");
	set_id(({ "robe" }));
	set_short("%^BLUE%^Dwarven %^RED%^War%^BLUE%^ Robe");
	set_obvious_short("a strong robe");
	set_long(
@AVATAR
%^BLUE%^This old Dwarven War Robe is a sacred dwarven item, used only by their strongest warriors, the robe is made of thick strong fabrics and is highly enchanted with dwarven runes running down each side of the robe.

AVATAR
	);
	set_weight(10);
	set_value(4000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",5);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^RED%^You wear the sacred robe.");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BLUE%^You remove the sacred robe.");
	TP->set_property("magic resistance",5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"The robe worn by "+ETO->query_cap_name()+" absorbes most of the damage.",({ETO,who}));
	tell_object(ETO,""+who->query_cap_name()+" strikes you but doesnt deal that much damage.");
	tell_object(who,"The robe of "+ETO->query_cap_name()+" absorbs most of the damage you inflict on him.");
		return (damage*60)/100;
	}
}
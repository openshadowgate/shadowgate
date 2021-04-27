#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven Robe");
	set_id(({ "robe", "dwarven robe", "dwarf robe", "small robe" }));
	set_short("%^BOLD%^%^WHITE%^Dwarven Robe%^RESET%^");
	set_obvious_short("%^MAGENTA%^brown robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This robe was obviously made to fit the frame of a dwarf.  It reaches almost to the ground and has several dwarven clan symbols woven into the front of it.  Woven onto the back are %^RED%^two crossing hammers%^BOLD%^%^WHITE%^, with the words %^RED%^Clan BattleSmite%^BOLD%^%^WHITE%^ woven underneath them.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(200);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+" slides on the roughly sewn "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^You slide the roughly sewn "+query_short()+"%^YELLOW%^ on.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+" quickly slides out of the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^You quickly slide out of the "+query_short()+"%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^RED%^"+who->query_cap_name()+"'s blow seems to be weakened as it strikes the "+query_short()+"%^RED%^ worn by "+ETO->query_cap_name()+"!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RED%^Your "+query_short()+" absorbs some of the force behind "+who->query_cap_name()+"'s blow!%^RESET%^");
	tell_object(who,"%^RED%^Your blow is weakened as it strikes the "+query_short()+"%^RED%^ worn by "+ETO->query_cap_name()+"%^RESET%^");
		return (damage*50)/100;
	}
}
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven BattlePlate");
	set_id(({ "armor", "armour", "plate", "fullplate", "battleplate", "dwarven armor", "dwarven fullplate", "dwarven battleplate" }));
	set_short("%^RED%^Dwarven BattlePlate%^RESET%^");
	set_obvious_short("small fullplate");
	set_long(
@AVATAR
%^RED%^This armor is forged from a %^YELLOW%^s%^BOLD%^%^WHITE%^p%^YELLOW%^a%^BOLD%^%^WHITE%^r%^YELLOW%^k%^BOLD%^%^WHITE%^l%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^g %^BOLD%^%^WHITE%^mithril%^RESET%^%^RED%^, which is rivited with several pieces of %^BOLD%^%^WHITE%^shiny%^GREEN%^ emerald%^RESET%^%^RED%^.  Engraved into the chest of it is a %^BOLD%^%^BLACK%^spiked war gauntlet, with a %^RESET%^%^RED%^blazing%^BOLD%^%^WHITE%^ silver%^BOLD%^%^BLACK%^ sword on the back of it,%^RESET%^%^BLUE%^two crossing hammers%^RESET%^%^RED%^ are engraved into the left shoulderplate.%^RESET%^

AVATAR
	);
	set_weight(52);
	set_value(10000);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^GREEN%^"+ETO->query_cap_name()+" slips into the perfectly fitted "+query_short()+"%^GREEN%^.%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^You slip into the perfectly fitted "+query_short()+"%^GREEN%^.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^GREEN%^"+ETO->query_cap_name()+" slips out of the perfectly fitted "+query_short()+"%^GREEN%^.%^RESET%^",TP);
	tell_object(TP,"%^GREEN%^You slip out of the perfectly fitted "+query_short()+"%^GREEN%^ with ease.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^YELLOW%^The "+query_short()+"%^YELLOW%^ worn by "+ETO->query_cap_name()+" seems to absorb the brunt of "+who->query_cap_name()+"'s blow!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Your "+query_short()+"%^YELLOW%^ absorbs the brunt of "+who->query_cap_name()+"'s blow!%^RESET%^");
	tell_object(who,"%^YELLOW%^The brunt of your blow is absorbed by the "+query_short()+"%^YELLOW%^ worn by "+ETO->query_cap_name()+"!%^RESET%^");
		return (damage*25)/100;
	}
}
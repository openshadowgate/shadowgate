#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^rot%^RESET%^");
	set_id(({ "rot" }));
	set_short("%^RESET%^%^GREEN%^rot%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^rot%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^It looks like some kind of %^BOLD%^%^GREEN%^rot%^RESET%^%^ORANGE%^ has infested your arm! The skin looks splotchy and some kind of %^YELLOW%^puss%^RESET%^%^ORANGE%^ oozes out of the wound.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
It appears that some kind of negative energy curse has infested this mold and it is now leaching your life force. On the plus side it likely gives some benefit of undeath.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("clothing");
	set_limbs(({ "left arm" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 999){
	tell_room(environment(query_worn()),"%^BOLD%^%^GREEN%^As "+who->QCN+" strikes "+ETOQCN+", it seems as if "+ETOQCN+"'s %^RESET%^%^ORANGE%^rotted skin%^BOLD%^%^GREEN%^ shrugs off the blow.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^As "+who->QCN+" strikes you, it seems as if your %^RESET%^%^ORANGE%^rotted skin%^BOLD%^%^GREEN%^ shrugs it off.%^RESET%^");
	tell_object(who,"%^BOLD%^%^GREEN%^As you strike "+ETOQCN+", it seems as if "+ETOQCN+"'s %^RESET%^%^ORANGE%^rotted skin%^BOLD%^%^GREEN%^ shrugs off the blow.%^RESET%^");
return (damage*0)/100;	}

}

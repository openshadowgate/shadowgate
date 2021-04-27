#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^Sh%^RESET%^i%^BLACK%^%^BOLD%^no%^RESET%^%^MAGENTA%^b%^BLACK%^%^BOLD%^i Sh%^RESET%^%^MAGENTA%^o%^BLACK%^%^BOLD%^z%^RESET%^o%^BLACK%^%^BOLD%^ku%^RESET%^");
	set_id(({ "robe", " uniform", " Shinobi", " Shinobi Shozoku" }));
	set_short("%^BLACK%^%^BOLD%^Sh%^RESET%^i%^BLACK%^%^BOLD%^no%^RESET%^%^MAGENTA%^b%^BLACK%^%^BOLD%^i Sh%^RESET%^%^MAGENTA%^o%^BLACK%^%^BOLD%^z%^RESET%^o%^BLACK%^%^BOLD%^ku%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black silk outfit%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^This outfit, made entirely of layers of %^RESET%^black silk%^BLACK%^%^BOLD%^, looks very expensive. It is oversized, then fastened with a complicated system of overlapping material that ties together. This allows the wearer to possibly hide several items in the folds of the cloth, and still move with great stealth and quickness. The inside of the outfit is deep %^RESET%^%^RED%^dark red%^BLACK%^%^BOLD%^, and it could easily be reversed if needed%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(5000);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ slips on the "+query_short()+"%^BLACK%^%^BOLD%^, moving around a little%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You slip on the "+query_short()+"%^BLACK%^%^BOLD%^, tying off all the loose ends and testing your movement%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ slips off the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You untie the "+query_short()+"%^BLACK%^%^BOLD%^ and slip out of it quietly%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BLACK%^%^BOLD%^Just as a blow is about to hit "+ETOQCN+", they step aside, as if melding into a sudden shadow%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^Just as you are about to be hit, you notice a shadow to your side, stepping into it for just a moment, evading the ill-timed blow%^RESET%^");
	tell_object(who,"%^BLACK%^%^BOLD%^Just as you are about to strike "+ETOQCN+"%^BLACK%^%^BOLD%^, they step aside and melt into a shadow%^RESET%^");
return (damage*40)/100;	}
}
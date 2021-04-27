#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("wooden crutch");
	set_id(({ "crutch", "tool", "wooden crutch" }));
	set_short("%^ORANGE%^a simple wooden crutch%^RESET%^");
	set_obvious_short("%^ORANGE%^a simple wooden crutch%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a very simple wooden crutch, made from a single tree branch that forms a natural "Y" shape where one could fit their underarms.  A handle has been nailed in halfway down the crutch and covered in leather for gripping.  It is a humble, ugly, but effective thing.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,3);
	set_large_wc(1,6);
	set_property("enchantment",0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" leans weakly against the crutch.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You lean weakly against the crutch.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" looks a little unsteady without the crutch.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You wobble unsteadily without the crutch.%^RESET%^");
	return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hide robe");
	set_id(({ "robe", "coat" }));
	set_short("%^BOLD%^%^BLACK%^Robe of the P%^RED%^r%^BLACK%^e%^RESET%^%^RED%^d%^BOLD%^a%^BLACK%^t%^RED%^o%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^fur robe lined with %^RED%^g%^BLACK%^o%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a fur robe made up of the hides of giant wolves.  The long, coarse hair of the hides is darkest grey, black in patches.  Dense and strong, it would provide protection from the elements as well as enemies in combat.  Although the coat itself is finely manufactured, the underside of the hides were intentionally left stained in %^RED%^blood%^RESET%^%^BOLD%^%^BLACK%^ and %^RESET%^%^RED%^gore%^BOLD%^%^BLACK%^.  It can be secured around the wearer by means of loops and %^WHITE%^polished fangs%^BLACK%^ standing in place for buttons.  The robe is particularly reinforced around the shoulders and collar, with long hairs sprouting forth and making its wearer appear even more menacing.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(2000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" gets a wild look in their eyes as they wear the robe.",ETO);
	tell_object(ETO,"%^ORANGE%^You feel ready to kill as you put on the robe.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" appears meeker as they remove the robe.",ETO);
	tell_object(ETO,"%^ORANGE%^You feel somehow meeker for a moment as you remove the robe.");
	return 1;
}


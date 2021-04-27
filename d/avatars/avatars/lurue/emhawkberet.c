#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cream colored beret");
	set_id(({ "beret", "cream beret", "hawk beret", "cap" }));
	set_short("%^RESET%^%^ORANGE%^Beret %^RESET%^of the %^BOLD%^%^GREEN%^E%^RESET%^m%^BOLD%^%^BLACK%^e%^GREEN%^ra%^RESET%^l%^BOLD%^%^GREEN%^d H%^RESET%^a%^BOLD%^%^BLACK%^w%^GREEN%^ks%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^RESET%^cream %^ORANGE%^colored beret%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^A wide oval of %^RESET%^cream felt %^ORANGE%^has been pressed and formed into the shape of this small beret.  Trimmed with a ribbon of %^GREEN%^green silk %^ORANGE%^to keep it tight upon the head, a small inner tie allows for minor adjustment of fit.  An embroidered badge of stiffened felt is sewn to left side of the cap, causing the majority of the material to flop to the right.  The badge is sewn in the style of a %^RESET%^fisted gauntlet %^ORANGE%^holding a brace of %^GREEN%^green arrows%^ORANGE%^.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
The mountaineers of Delshen Hold were known for their crisp, uniform style of dress and their skill at maneuvering through the wilds of their mountainous homelands.  Dressed in cream and green, their favorite tactic was to lay in wait above the pass till their enemy crossed through and then fire down hundreds of green fletched arrows.  Because of this they were often referred to as the emerald hawks.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" sets their "+query_short()+"%^BOLD%^%^GREEN%^ atop their head and gives a crisp salute!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You slide the beret on cinch the tie tight, nothing will keep you from your mission!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" rolls up their "+query_short()+"%^BOLD%^%^GREEN%^ and puts it away.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You slip the beret from your head and roll it up before putting it away.%^RESET%^");
	return 1;
}


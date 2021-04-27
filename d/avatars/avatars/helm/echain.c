#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("elven chain mail");
	set_id(({ "elven", "chain", "elven chain", "elven chain mail", "chain mail", "armor", "shirt", "chain shirt" }));
	set_short("%^RESET%^%^BOLD%^elven %^RESET%^%^GREEN%^chain mail%^RESET%^");
	set_obvious_short("a beautifully crafted chain shirt");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This is a lightweight suit of gleaming steel armor that has been intricately woven into a thin and tight chain mesh. Each section of links displays a pattern of its own and with every movement a new pattern appears. At a closer look thin threads of a dull green metal appear throughout the patterns in a seemingly random fashion. If you watch this suit from afar it appears a silvery green.

AVATAR
	);
	set_weight(8);
	set_value(0);
	set_lore(
@AVATAR
This is the legendary armor of the great elven artisans. It is created from an alloy of fine steel and mithril, whose blending is a closely-guarded secret.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck", "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	ETO->set_property("magic resistance",5);
	return 1;
}

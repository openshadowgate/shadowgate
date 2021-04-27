#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BLUE%^Midnight blue %^WHITE%^Wizard%^RESET%^%^BLUE%^robes.%^RESET%^");
	set_id(({ "robe", " robes", " wizard robe", " wizard robes" }));
	set_short("%^BLUE%^Midnight blue %^WHITE%^Wizard%^RESET%^%^BLUE%^robes.%^RESET%^");
	set_obvious_short("%^BLUE%^blue robes%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^This robe is long and elaborate. It flows all the way down to the feet and nearly touches the floor. The fabric is thick, soft, and of the highest quality. The robe has been dyed a deep blue. It is so dark it seems the folds of the robe actually absorb light. Along the brim of the robe a %^WHITE%^silver%^BLUE%^ lining has been stitched into the robe's fabric. On the back of the robe seven %^WHITE%^silver stars%^BLUE%^ have been placed in a circular pattern.%^RESET%^

AVATAR
	);
	set_weight(30);
	set_value(3000);
	set_max_internal_encumbrance(30);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,""+ETO->query_cap_name()+" wraps "+query_short()+" around his body.",TP);
	tell_object(TP,"You wear "+query_short()+" and the world becomes a shade darker yet better defined.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,""+ETO->query_cap_name()+" removes "+query_short()+" and blinks a few times in silent surprise.",TP);
	tell_object(TP,"You remove "+query_short()+" and your vision returns to normal.");
	ETO->set_property("magic resistance",5);
	return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ivory ring");
	set_id(({ "ring" }));
	set_short("%^RESET%^%^BOLD%^A small ivory ring%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^A small ivory ring%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^Made of ivory, this small ring is very plain, devoid of stones, or engravings. It is perfectly white, as white as pure snow, almost too white for ivory. The ring is perfectly smooth, and cool to the touch%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" slips on the "+query_short()+"%^RESET%^%^ORANGE%^, they smile softly%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^As you slip on the "+query_short()+"%^RESET%^%^ORANGE%^, you can hear the soft laughter of a child%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" slips off the "+query_short()+"%^RESET%^%^ORANGE%^, they smile softly%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^As you slip off the "+query_short()+"%^RESET%^%^ORANGE%^, you can hear the soft laughter of a child%^RESET%^");
	return 1;
}

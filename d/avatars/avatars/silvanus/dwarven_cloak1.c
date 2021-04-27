#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarven Cloak");
	set_id(({ "cloak", "dwarven cloak", "dwarf cloak" }));
	set_short("%^BLUE%^Dwarven Cloak%^RESET%^");
	set_obvious_short("%^BLUE%^blue cloak%^RESET%^");
	set_long(
@AVATAR
%^RED%^This cloak is made from a %^BLUE%^dark blue fabric%^RED%^, obviously woven to fit a small person.  Sewn into the cloth are several dwarven clan symbols, one which is that of %^BLUE%^two hammers crossing.%^RESET%^ 

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BLUE%^"+ETO->query_cap_name()+" wears the comfortable "+query_short()+"!%^RESET%^",TP);
	tell_object(TP,"%^BLUE%^You wrap the "+query_short()+" snuggly around your neck!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BLUE%^"+ETO->query_cap_name()+" takes off the comfortable "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^BLUE%^You unwrap the "+query_short()+" from around your neck!%^RESET%^");
	return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ivory ring");
	set_id(({ "ring" }));
	set_short("%^RESET%^%^BOLD%^s%^RESET%^m%^BOLD%^all ivo%^RESET%^r%^RESET%^%^BOLD%^y r%^RESET%^i%^RESET%^%^BOLD%^ng%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^s%^RESET%^m%^BOLD%^all ivo%^RESET%^r%^RESET%^%^BOLD%^y r%^RESET%^i%^RESET%^%^BOLD%^ng%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^made of %^BOLD%^ivory%^RESET%^, this small ring is very plain, devoid of stones and engravings on the outside. Instead, the smooth cool ivory seems to almost glow in its simplicity. There is %^BLACK%^%^BOLD%^writing%^RESET%^ along the inside of the ring%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BLACK%^%^BOLD%^Even in the darkest of times, we must remember the will of the light, and the laughter of children%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(10);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETOQCN+"%^RESET%^%^CYAN%^ slips on the ring, a smile crosses their features%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^As you slip on the "+query_short()+"%^RESET%^%^CYAN%^, soft children's laughter can be heard%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETOQCN+"%^RESET%^%^CYAN%^ slips off the ring, a smile crosses their features%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^As you slip on the "+query_short()+"%^RESET%^%^CYAN%^, soft children's laughter can be heard%^RESET%^");
	return 1;
}

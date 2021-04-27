#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("test");
	set_id(({ "test", "test weapon" }));
	set_short("Test weapon");
	set_obvious_short("Test weapon");
	set_long(
@AVATAR
test weapon

AVATAR
	);
	set_weight(2);
	set_value(1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"They wear test",TP);
	tell_object(TP,"You wear test");
	return 1;
}
int remove_func(){
	tell_room(ETP,"they remove test",TP);
	tell_object(TP,"your remove test");
	return 1;
}

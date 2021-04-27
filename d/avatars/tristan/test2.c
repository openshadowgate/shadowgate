#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("test2");
	set_id(({ "test", " test 2" }));
	set_short("Test 2");
	set_obvious_short("test 2");
	set_long(
@AVATAR
test 2 

AVATAR
	);
	set_weight(2);
	set_value(2);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"They remove test",TP);
	tell_object(TP,"You remove test");
	TP->add_stat_bonus("dexterity",2);
	return 1;
}
int remove_func(){
	tell_room(ETP,"They remove test",TP);
	tell_object(TP,"You remove test");
	TP->add_stat_bonus("dexterity",-2);
	return 1;
}

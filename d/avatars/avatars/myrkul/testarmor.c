#include <std.h>
inherit "/d/common/obj/armour/breastplate";

void create(){
	::create();
	set_name("testarmor");
	set_id(({ "breastplate" }));
	set_short("Breastplate");
	set_obvious_short("Breastplate");
	set_long("Breastplate
");
	set_value(10);
	set_size(2);
	set_property("enchantment",0);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"ping");
	}

}

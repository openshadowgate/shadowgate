#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shoeofwoe");
	set_id(({ "shoe" }));
	set_short("mighty shoe of woe");
	set_obvious_short("mighty shoe of woe");
	set_long(
@AVATAR
mighty shoe of woe

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"");
return (damage*100)/100;	}
}
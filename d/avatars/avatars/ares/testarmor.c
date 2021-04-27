#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("testarmor");
	set_id(({ "armor" }));
	set_short("armor");
	set_obvious_short("armor");
	set_long(
@AVATAR
armor

AVATAR
	);
	set_weight(1);
	set_value(1);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 999){
	tell_room(environment(query_worn()),"test",({ETO,who}));
	tell_object(ETO,"test");
	tell_object(who,"test");
		who->do_damage("torso",roll_dice(10,10));
return damage;	}
}
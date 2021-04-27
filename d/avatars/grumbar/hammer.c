#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("hammer");
	set_id(({ "hammer", "medium hammer", "war hammer" }));
	set_short("hammer");
	set_obvious_short("medium hammer");
	set_long(
@AVATAR
nice hammer

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_lore(
@AVATAR
200

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("hammer");
	set_size(2);
	set_wc(2,4);
	set_large_wc(2,4);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),""+targ->query_cap_name()+" shivers as "+ETO->query_cap_name()+" hits them.",({ETO,targ}));
	tell_object(ETO,""+targ->query_cap_name()+" shivers as you hit them.");
	tell_object(targ,"You shiver from the cold as "+ETO->query_cap_name()+" hits you with the "+query_short()+".");
		return roll_dice(2,3)+-1;	}
}	set_type("slashing");
	set_prof_type("~q");
	set_size(^);
	set_wc(3,3);
	set_large_wc(3,3);
	set_property("enchantment",3);
	set_ac(3);
}



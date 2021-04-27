#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
	::create();
	set_name("two");
	set_id(({ "sword" }));
	set_short("two handed sword");
	set_obvious_short("two handed sword");
	set_long("two handed sword
");
	set_value(0);
	set_property("enchantment",5);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"special",({ETO,targ}));
	tell_object(ETO,"special");
	tell_object(targ,"special");
		return roll_dice(2,10)+0;	}

}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hidearmor");
	set_id(({ "hide", "Hide" }));
	set_short("Demonic hide");
	set_obvious_short("crude hide armor");
	set_long(
@AVATAR
At first glance the armor looks to be a rather crude suit of hide armor. At a closer look you find that this armor is made up of some demons hide, and just looks a bit crude. The whole armor is made up of one length of hide, wrapped around to finish the armor. The hide is a dark blue to black color and almost looks glossy.

AVATAR
	);
	set_weight(20);
	set_value(1500);
	set_property("lore difficulty",0);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(3);
	set_property("enchantment",3);
	set_ac(4);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"");
return (damage*-50)/100;	}
}
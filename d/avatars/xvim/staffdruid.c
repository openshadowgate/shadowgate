#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Staff of the druids");
	set_id(({ "staff" }));
	set_short("%^GREEN%^Staff of the druids");
	set_obvious_short("%^GREEN%^Staff of the druids");
	set_long(
@AVATAR
This staff is made out of gnarly old oak wood, it has the head of a unicorn at the end of it.

AVATAR
	);
	set_weight(15);
	set_value(500);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(2);
	set_wc(3,5);
	set_large_wc(3,5);
	set_property("enchantment",2);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 80){
	tell_room(environment(query_wielded()),"%^WHITE%^The Unicorn horn penetrates "+targ->query_cap_name()+" skin, and "+targ->query_cap_name()+" twitches in pain",({ETO,targ}));
	tell_object(ETO,"%^WHITE%^The Unicorn horn penetrates "+targ->query_cap_name()+" skin, and "+targ->query_cap_name()+" twitches in pain");
	tell_object(targ,"%^WHITE%^The Unicorn horn penetrates your skin, and you feel numb");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}
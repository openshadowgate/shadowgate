#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("perfect shotokan fist");
	set_id(({ "fist", "guantlet", "perfect fist" }));
	set_short("%^BOLD%^%^WHITE%^Perfect Shotokan Fist%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A stark white karate gauntlet%^RESET%^");
	set_long(
@AVATAR
This is a stark white karate gauntlet made of light leather.  It looks
like it would fit well to the wearers left fist.  The knuckles have been
left open to allow more freedom of movement.

AVATAR
	);
	set("read",
@AVATAR
Tatsumaki Senoukyaku

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("shotokanfist");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",5);
	set_ac(2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),""+ETOQCN+" jumps into the air and scream %^BOLD%^%^WHITE%^Tatsumaki Senoukyaku%^RESET%^, hitting "+targ->QCN+" with a devastating hurricane kick.",({ETO,targ}));
	tell_object(ETO,"You jump into the air and scream %^BOLD%^%^WHITE%^Tatsumaki Senoukyaku%^RESET%^, hitting "+targ->QCN+" with a devastating hurricane kick.");
	tell_object(targ,""+ETOQCN+" jumps into the air and scream %^BOLD%^%^WHITE%^Tatsumaki Senoukyaku%^RESET%^, hitting you with a devastating hurricane kick.");
		return roll_dice(5,6)+0;	}
}
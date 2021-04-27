#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("furious shotokan fist");
	set_id(({ "fist", "gauntlet", "furious fist" }));
	set_short("%^BOLD%^%^RED%^Furious Shotokan Fist%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A deep red karate gauntlet%^RESET%^");
	set_long(
@AVATAR
This is a deep red karate gauntlet made of tough leather.  It looks like
it would fit well onto the wearer's right fist.  The knuckles have been
ridged and you surmise it would do terrible damage to anyone hit by it

AVATAR
	);
	set("read",
@AVATAR
Shouryuken!

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
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),""+ETOQCN+" screams %^BOLD%^%^RED%^Shouryuken %^RESET%^and hits "+targ->QCN+" with a devastating rising uppercut.",({ETO,targ}));
	tell_object(ETO,"You scream %^BOLD%^%^RED%^Shouryuken %^RESET%^and hit "+targ->QCN+" with a devastating rising uppercut.");
	tell_object(targ,""+ETOQCN+" screams %^BOLD%^%^RED%^Shouryuken %^RESET%^and hits you with a devastating rising uppercut.");
		return roll_dice(5,6)+0;	}
}
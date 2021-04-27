#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Staff of the Archmagi");
	set_id(({ "staff" }));
	set_short("%^RED%^Staff of the %^BOLD%^%^BLACK%^Archmagi");
	set_obvious_short("%^RED%^Staff of the %^BOLD%^%^BLACK%^Archmagi");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The old long gnarly staff looks like a true weapon of a magi. It is about 3 feet long, with a large %^RED%^red gem %^BOLD%^%^BLACK%^embedded in one end of it. When used it sends out strong lightning bolts that scorch anything it hits.

AVATAR
	);
	set_weight(15);
	set_value(0);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(1);
	set_wc(6,1);
	set_large_wc(8,1);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 125){
	tell_room(environment(query_wielded()),"%^YELLOW%^A lightning bolt flies out of the red gem, and hits "+targ->query_cap_name()+" with immense power",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^A lightning bolt flies out of the red gem, and hits "+targ->query_cap_name()+" with immense power");
	tell_object(targ,"%^YELLOW%^A lightning bolt flies out of the red gem, and hits you with immense power");
		return roll_dice(25,4)+-15;	}
}
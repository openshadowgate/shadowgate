#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("talon");
	set_id(({ "talon", "claw", "talons", "claws", "roc claw", "roc talon" }));
	set_short("%^RESET%^%^ORANGE%^the claw from a roc%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is the enormously large claw of a roc.  A mythical bird as big as a barn and incredibly nasty in temperament. %^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(1000);
	set_type("piercing");
	set_prof_type("roc-claw");
	set_size(4);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^YELLOW%^The roc's talons tear into your flesh!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The roc's talons tear into your flesh!!%^RESET%^");
	tell_object(targ,"%^YELLOW%^The roc's talons tear into your flesh!!%^RESET%^");
		return roll_dice(2,4)+2;	}

}

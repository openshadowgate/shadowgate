#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("tambourine");
	set_id(({ "tambourine", "silver tambourine", "misfortune's song" }));
	set_short("%^BOLD%^%^BLACK%^M%^WHITE%^i%^MAGENTA%^s%^BLACK%^fort%^MAGENTA%^u%^WHITE%^n%^BLACK%^e's S%^WHITE%^o%^MAGENTA%^n%^BLACK%^g%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^silver tambourine%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This crescent shaped tambourine is made of a wide band of %^WHITE%^silvery metal %^BLACK%^with several oval holes along its outer length.  Inset into these holes are %^WHITE%^silver cymbals %^BLACK%^that chime brightly when the tambourine is shaken.  The %^WHITE%^silvery sound %^BLACK%^is bright and cheery, though an odd %^MAGENTA%^disharmonic undertone %^BLACK%^makes for a less then pleasing sound. %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_type("piercing");
	set_prof_type("instrument");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,4);
	set_property("enchantment",5);
	set_ac(5);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+targ->QCN+" grips their head in pain as the %^MAGENTA%^disharmonic %^WHITE%^sound of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^chimes!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The cymbals of the "+query_short()+" %^BOLD%^%^WHITE%^chime with a %^MAGENTA%^disharmonic %^WHITE%^sound causing "+targ->QCN+" to clutch at their head in pain.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^The cymbals of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^chime with a %^MAGENTA%^disharmonic %^WHITE%^sound and you feel your heart stop and your mind succumb to pain as the sounds batter your senses. %^RESET%^");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Night's Veil");
	set_id(({ "katar", "dagger", "punching dagger", "weapon" }));
	set_short("%^BOLD%^%^BLUE%^Night's Veil%^RESET%^");
	set_obvious_short("katar");
	set_long(
@AVATAR
This is a katar, or more commonly known as a punching dagger. The blade appears to be forged out of silvery mithril but covered with some form of weaponblack that dulls the metallic surface of the weapon. A grip is mounted at ninety degrees to the blade between two parallel metal bars.

AVATAR
	);
	set_weight(2);
	set_value(357);
	set_type("slashing");
	set_prof_type("katar");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ jabs the katar forcefully into "+targ->query_cap_name()+"%^BOLD%^%^BLUE%^.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You jab the katar forcefully into your opponent.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"%^BOLD%^%^BLUE%^ jabs the katar forcefully into you.%^RESET%^");
		return roll_dice(2,3)+-1;	}
}
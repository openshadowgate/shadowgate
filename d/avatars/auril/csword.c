#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("razor's edge");
	set_id(({ "sword", "longsword", "long sword", "razor's edge", "weapon" }));
	set_short("%^RESET%^%^BLUE%^Razor's Edge%^RESET%^");
	set_obvious_short("Longsword");
	set_long(
@AVATAR
The blade of this longsword is forged from %^RESET%^%^BLUE%^cold steel%^RESET%^ and has a deep %^BOLD%^%^RED%^blood groove%^RESET%^ along its length which seems to flow blood endlessly.  The crosspiece of the weapon is a depiction of the heads of two %^RESET%^%^GREEN%^serpents%^RESET%^, jaws open and ready to strike.  Set into the middle of the handle which is wrapped in %^BOLD%^%^BLACK%^blackened%^RESET%^ steel wire is a %^BOLD%^%^RED%^blood-red%^RESET%^ ruby, and the pommel is a human %^BOLD%^%^BLACK%^skull%^RESET%^, with smaller rubies set into the eyesockets.

AVATAR
	);
	set_weight(11);
	set_value(10000);
	set_lore(
@AVATAR
This weapon is granted to faithful followers of Cyric, to be used for murder and strife in his name.

AVATAR
	);
	set_type("slashing");
	set_prof_type("razor");
	set_size(2);
	set_wc(2,6);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You grip the weapon and a feeling of murderous intent washes over you.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel more calm as your sanity returns.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You feel great satisfaction as your weapon rends through flesh.");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s blade cuts deep into your skin and you begin to feel sick.");
		targ->set_paralyzed(roll_dice(1,4)+2);
return 0;	}
}
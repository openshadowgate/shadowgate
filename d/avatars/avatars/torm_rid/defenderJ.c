#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Defender of Justice");
	set_id(({ "sword", "longsword", "long sword", "defender" }));
	set_short("%^BOLD%^%^BLUE%^Defender of %^WHITE%^J%^YELLOW%^u%^WHITE%^s%^YELLOW%^t%^WHITE%^i%^YELLOW%^c%^WHITE%^e");
	set_obvious_short("%^BOLD%^%^WHITE%^Marble longsword");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^With a powerfull %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^ aura that surrounds the sword, it appears to be made of marble. %^BOLD%^%^BLACK%^Black %^BOLD%^%^WHITE%^and white flowing together like the stone. Set between the sharp blades, deep %^RESET%^%^RED%^red%^BOLD%^%^WHITE%^ runes are ingraved, giving an even more ancient and magical feel to it. The sword itself is 4 feet long, incredebly sharp, and heavy, but rather thin, so it can cut though any materiel without much effort. Set between the blade and handle, a 3 inch wide perfectly square plate made of %^YELLOW%^gold%^BOLD%^%^WHITE%^, to protect the wielders hand from any weapon sliding the the length of the blade. The handle is wrapped in %^RESET%^%^WHITE%^silver%^BOLD%^%^WHITE%^ cloth.

AVATAR
	);
	set_weight(35);
	set_value(0);
	set_type("slashing");
	set_prof_type("defender");
	set_size(2);
	set_wc(4,6);
	set_large_wc(5,6);
	set_property("enchantment",5);
	set_ac(10);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^As "+TP->query_cap_name()+" wields the "+query_short()+" the runes %^BOLD%^%^RED%^spark %^BOLD%^%^WHITE%^and blow bright %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^!",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^The runes %^BOLD%^%^RED%^spark%^BOLD%^%^WHITE%^ and glow bright %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^!");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^As "+TP->query_cap_name()+" releases the "+query_short()+" the runes dim.",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^As you release your grip on the $N the "+query_short()+" the runes dim.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^With what seems like little effort "+ETO->query_cap_name()+" slices through "+targ->query_cap_name()+".",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^With little effort you slice through "+targ->query_cap_name()+".");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" slices through you with little effort.");
		return roll_dice(3,6)+0;	}
}
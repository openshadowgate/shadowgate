#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("scalpel");
	set_id(({ "scalpel", "dagger", "blade" }));
	set_short("%^BOLD%^%^WHITE%^a r%^RED%^u%^BOLD%^s%^RESET%^%^RED%^t%^BOLD%^%^WHITE%^y scalpel%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a r%^RED%^u%^BOLD%^s%^RESET%^%^RED%^t%^BOLD%^%^WHITE%^y scalpel%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This impressive blade is an old surgical instrument.  It looks as though it was forged from a single sheet of steel, but the handle has been decorated to look like a staff wound by serpents with %^GREEN%^eme%^BOLD%^ra%^RESET%^%^GREEN%^ld %^BOLD%^%^WHITE%^eyes.  The short, fine blade is still honed to impressive sharpness, but it is beginning to %^BOLD%^%^RED%^r%^RESET%^ORANGE%^u%^RED%^st %^BOLD%^%^WHITE%^with age.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(130);
	set_lore(
@AVATAR
A medical doctor named Hephelios is widely credited with bringing medical
advances to the Realm from faraway lands.  He trained many students, but
Ghaelion is perhaps the most notorious.  Ghaelion took his oaths to do no
harm very seriously, and even practiced his medicine on monsters.  He is
know to have been felled by a drow that he treated, killed by his own
surgical blade.

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^As "+ETOQCN+" wields the scalpel, their eyes are filled with bloodlust!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel ready to...operate!!!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^As "+ETOQCN+" unwields the scalpel, they look more sane.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You calm down, now rid of the scalpel.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 120){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^As "+ETOQCN+" makes a surgical strike to the vitals of "+targ->QCN+", the area is sprayed in blood!!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You make a surgical strike on the vitals of "+targ->QCN+", spraying you in their blood!!!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^As "+ETOQCN+" cuts you along a vital area, you begin to bleed in spurts and gushes!!%^RESET%^");
		return roll_dice(2,4)+1;	}
}
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Stiletto of Cruelty");
	set_id(({ "dagger", " stiletto", " sword", " short sword", " longsword", " long sword", " crueltyblade" }));
	set_short("%^BOLD%^%^BLACK%^Stiletto of %^RED%^Cruelty%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Stiletto of %^RED%^Cruelty%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This small dark blade oozes with evil and cruelty, venom dripping from its blade. Beware this is a weapon of the gods!

AVATAR
	);
	set("read",
@AVATAR
Xvim's Weapon of Choice

AVATAR
	);
	set_weight(50);
	set_value(0);
	set_lore(
@AVATAR
0

AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(50,20);
	set_large_wc(50,20);
	set_property("enchantment",25);
	set_ac(115);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^The blade chants dark mystic texts as its wielded",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^The blade chants dark mystic texts as its wielded");
	TP->do_damage("torso",random(500));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^BLACK%^The blade stops chanting about eternal damnation",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^The blade stops chanting about eternal damnation");
	TP->do_damage("torso",random(500));
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The dark blade chants: "Death to thee I hit, Power to my wielder, the circle is complete"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The dark blade chants: "Death to thee I hit, Power to my wielder, the circle is complete"");
	tell_object(targ,"%^BOLD%^%^BLACK%^The dark blade chants: "Death to thee I hit, Power to my wielder, the circle is complete"");
	}
}
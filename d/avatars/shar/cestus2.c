#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("cestus");
	set_id(({ "cestus", "cestus of the silver rings", "knuckles" }));
	set_short("%^RESET%^%^MAGENTA%^Cestus of the %^BOLD%^%^WHITE%^Silver Rings%^RESET%^");
	set_obvious_short("A leather glove");
	set_long(
@AVATAR
%^MAGENTA%^ At first this just seems like a pair of fingerless gloves, but it is more that just that.  The cestus is made of a soft leather that is as strong as flexible.  The glove slips on to rest tight against the wrist.  Leather cordin is used to tighten the glove.  Strip of metal are sandwiched between two layers of leather.  On the back of the glove four interlocking rings in %^BOLD%^%^WHITE%^silver%^RESET%^%^MAGENTA%^ have been tooled into the leather.  The cestus is often a pugelists' weapon of choice, giving that they tend to rely on their brute strength rather than weapons.

AVATAR
	);
	set_weight(4);
	set_value(350);
	set_lore(
@AVATAR
The Cestus of the Silver Rings are worn by the monks of Ibrandul in defense of their temple.  The monks spend countless hours honing their bodies into deadly weapons. It is possilbe for an outside to gain one of these gloves, but no one yet has used them to the deadly accuracy that the monks have.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,2);
	set_large_wc(1,2);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^MAGENTA%^"+ETO->query_cap_name()+" slips on the glove and pulls the laces taunt, getting a nice snug fit.",TP);
	tell_object(TP,"%^MAGENTA%^You slip on the gloves and pull the laces taunt, getting a nice snug fit.");
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^MAGENTA%^"+ETO->query_cap_name()+" unlaces the glove and slips it off.",TP);
	tell_object(TP,"%^MAGENTA%^You unlace the glove and slip them off.");
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" moves with lightning speed and delivers a series of rabbit punches to "+targ->query_cap_name()+"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You move in with lightning speed and deliver a series of rabbit punches to "+targ->query_cap_name()+"");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" moves with lightning speed and delivers a series of rabbit punches.");
		return roll_dice(5,2)+0;	}
}
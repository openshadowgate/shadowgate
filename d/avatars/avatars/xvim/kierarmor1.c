#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armorforkier");
	set_id(({ "armor", "studded", "leather" }));
	set_short("%^BLACK%^%^BOLD%^Mantle of Lost Empires%^RESET%^");
	set_obvious_short("%^BLUE%^blue scale%^RESET%^ studded");
	set_long(
@AVATAR
Crafted from %^BLUE%^bl%^GREEN%^uis%^BLUE%^h%^RESET%^ %^GREEN%^green%^RESET%^ scales, this studded is heavier then most sets, but provide an amazing amount of protection for the weight. Large scales make up the shoulders and chest of the armor, with smaller ones making up the bulk of the suit. Studs formed of %^BLACK%^%^BOLD%^cold iron%^RESET%^ dot the armor. It buckles along the side with %^ORANGE%^strong leather straps%^RESET%^ and %^BLACK%^%^BOLD%^iron buckles%^RESET%^. As you watch the armor, you swear

AVATAR
	);
	set_weight(12);
	set_value(0);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^As "+ETOQCN+" buckles on the armor, a sudden flash of light glances off the armor. You swear you see a %^RED%^burning city%^RESET%^ reflected in the scales",ETO);
	tell_object(ETO,"%^RESET%^As you buckle on the armor, your mind is filled with images of a %^RED%^city burning%^RESET%^, and a mighty tower falling");
	return 1;
}
int remove_func(){
tell_room(environment(ETO),""+ETOQCN+" sighs heavily as "+ETO->query_subjective()+" removes "+ETO->query_possessive()+" armor. A look of grief crosses "+ETO->query_possessive()+" face for a moment, then is gone",ETO);
	tell_object(ETO,"As you unbuckle the armor, you smell smoke and ash, though in a moment you barely remember it");
	return 1;
}
int strike_func(int damage, object what, object who){
  if(random(1000) < 100){
tell_room(EETO," %^BLACK%^%^BOLD%^Just as about "+ETOQCN+" is hit, there is a loud crash and the blow seems to glance off of "+ETO->query_objective()+"%^RESET%^",({ETO}));
	tell_object(ETO,"%^BLACK%^%^BOLD%^As the blow is about to hit, you feel a rush of energy and as you are struck you suddenly hear a crash and smell smoke%^RESET%^");
	tell_object(who,"");
return (damage*10)/100;	}
}

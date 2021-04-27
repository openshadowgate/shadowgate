#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shocking grasp");
	set_id(({ "shocking grasp", "blue leather glove", "glove", "leather glove" }));
	set_short("%^BOLD%^%^BLUE%^S%^YELLOW%^h%^BLUE%^o%^YELLOW%^c%^BLUE%^k%^YELLOW%^i%^BLUE%^n%^YELLOW%^g%^BLUE%^ Gr%^YELLOW%^a%^BLUE%^sp%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A blue leather glove%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Supple blue leather is used in the creation of this glove.  The thin leather is flexible and light enough to give full freedom to the hand, but offers a fair ammount of protection.  Across the knuckles and back of the hand heavy padding give some extra heft to the glove.  %^CYAN%^Electrum%^BLUE%^ spikes are imbedded into the leather across the knuckles, giving it a deadly image.  Veins of %^YELLOW%^yellow%^BLUE%^ jagged lines fork across the leather, looking akin to lightning bolts.  The fi

AVATAR
	);
	set_weight(6);
	set_value(1500);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^Shocking Graps is a glove used by the Monks of the Four Silver Rings, a religous order devoted to the slain god Ibrandul.  This glove in paticular seems to center around one monk in paticular, Yaldran Stormfists.  Yaldran was a human monk of the order that loved to engage in brawls and melee against the invaders of the monistary.  His love for fighting was frowned upon by many of the more reserved monks, who adopted a more peaceful lifestyle.  Yaldran delighted in any chance he got to engag

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("piercing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" pulls on their glove, %^YELLOW%^crackling yellow runes%^BLUE%^ flash into existance across the back of their hand.  Wrapping around their fist is a %^B_BLUE%^%^YELLOW%^electrical aura%^RESET%^%^BLUE%^ that crackles and sparks wildly.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As you pull on the glove %^YELLOW%^crackling yellow runes%^BLUE%^ flash into existance across the back of the glove.  An %^B_BLUE%^%^YELLOW%^electrical aura%^RESET%^%^BLUE%^ crackles and sparks around your fist.");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The energy around "+ETOQCN+"'s hand flashes once and then is gone silently.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The energy around your hand flashes once and then is gone silently, much like a bolt of lighting, allowing you to remove the glove with ease.");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
   if(!objectp(targ)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^In a quick flash, "+targ->QCN+" is shocked with an electrical discharge as "+ETOQCN+" rips into them.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^Quickly flaring out with an electrical discharge, the aura around your fist rips through "+targ->QCN+", before  subsiding back to it's normal aura.");
	tell_object(targ,"%^BOLD%^%^BLUE%^In a quick flash, $T is shocked with an electrical discharge as "+ETOQCN+" rips into you, leaving your muscles twitching for a bit from the energy");
		return roll_dice(2,4)+2;	}
}

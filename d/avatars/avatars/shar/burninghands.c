#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("burning hands");
	set_id(({ "glove", "red leather glove", "burning hands", "fire glove" }));
	set_short("%^BOLD%^%^RED%^B%^RESET%^u%^BOLD%^r%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^RESET%^%^ORANGE%^ H%^RED%^a%^ORANGE%^n%^RED%^d%^ORANGE%^s");
	set_obvious_short("%^RESET%^%^RED%^fiery red leather glove%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^Fiery thick red leather is used in the creation of this glove.  The glove is heavily padded across the knuckles and the back of the hand, giving it some solid weight.  %^YELLOW%^Brass%^RED%^spikes are imbedded across the knuckles, adding a deadly touch to these gloves.  A chaotic pattern of flames in various shades of %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^, %^RESET%^%^ORANGE%^orange%^BOLD%^%^RED%^, and %^YELLOW%^yellow%^RED%^ are imbedded into the leather.  While the glove is fingerless, strips of %^YELLOW%^bronze%^RED%^ are imbedded into the leather around each opening, sealing off the leather.

AVATAR
	);
	set_weight(6);
	set_value(1500);
	set_lore(
@AVATAR
%^RED%^Manufactured by the Monks of Ibrandul, the Burning Hands glove adds some leather fiery damage to their attacks.  The gloves seem to center around one paticular monk, Oredel the Brash.  There are a couple stories about how Oredel took it upon himself to hunt down followers of Shar after the goddess slew the god Ibrandul.  With his burning fists, Oredel was relentless in slaying any Sharrians he could find.  His life though came to an end when we tried to assassinate an archbishop of the Mistress of the Night's faith in the winter of 513.

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
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" pulls on the leather glove around his hand.  %^YELLOW%^Golden runes%^RED%^ flare to life across the back of their hand.  An instant later their hand is surrounded with a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^BOLD%^%^RED%^ effigy.",ETO);
	tell_object(ETO,"%^RED%^You pull on the leather gloves tightly around your hand, suddenly %^YELLOW%^golden runes%^RED%^ flare to life on the back of your fist.  A fiery effigy rises from the runes to wrap your hands in %^B_RED%^%^YELLOW%^flames%^RESET%^%^RED%^!");
	ETO->add_attack_bonus(2);
	ETO->add_damage_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RED%^The flames around "+ETOQCN+"'s hand disipates, as they pull the glove off.",ETO);
	tell_object(ETO,"%^RED%^The flames around your hand disipate, allowing you to remove the glove");
	ETO->add_attack_bonus(-2);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^The flames around "+targ->QCN+"'s hand grows brighter and more intense just before they pummel %^T%^ with a fiery blow.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^The flames grow more intense, flaring in a fiery burst, delivering their burning rage onto "+targ->QCN+"");
	tell_object(targ,"%^BOLD%^%^RED%^The flames around $T's hand grows brighter and more intense just before they pummel $T with a fiery blow.");
		return roll_dice(2,4)+2;	}
}
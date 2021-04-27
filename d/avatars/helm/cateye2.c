#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pearl");
	set_id(({ "pearl", "eye", "necklace", "pendant" }));
	set_short("%^RESET%^A sickly %^YELLOW%^yellow%^RESET%^ pearl");
	set_obvious_short("%^RESET%^A sickly %^YELLOW%^yellow%^RESET%^ pearl");
	set_long(
@AVATAR
This...pearl, for the lack of a better word is pulsating with an inner glow. It is heavily stained by ash and is about the size of an...eye. A sickly yellow eye. A thin steel chain is fastened to it so that you can wear it over your head.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This could indeed be the eye of a certain cat, although it appears to have been treated in such a fashion that the pupil has been removed. Why is anyone's guess.

AVATAR
	);
	set_property("lore difficulty",6);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel a strange presence.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You don't seem to feel the strange presence any longer.");
	return 1;
}

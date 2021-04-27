#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pearl");
	set_id(({ "pearl", "necklace", "pendant", "eye" }));
	set_short("%^RESET%^A sickly %^YELLOW%^yellow%^RESET%^ pearl");
	set_obvious_short("%^RESET%^A sickly %^YELLOW%^yellow%^RESET%^ pearl");
	set_long(
@AVATAR
This...pearl, for the lack of a better word is pulsating with an inner glow. It is heavily stained by ash and is about the size of an...eye. A sickly yellow eye. A thin steel chain is fastened to it so that you can wear it over your head.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
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
	tell_object(ETO,"The feeling of being watched subsides.");
	return 1;
}

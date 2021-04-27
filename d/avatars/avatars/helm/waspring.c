#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "copper ring", "old copper ring", "old ring", "waspring", "ring of the wasp" }));
	set_short("%^RESET%^%^CYAN%^ring of the wasp%^RESET%^");
	set_obvious_short("an old copper ring");
	set_long(
@AVATAR
This ring was probably once very beautiful but now it is completely covered with verdigris. Only very vague traces of ornament can be felt underneath your fingertips as you brush the corruption of the metal aside. You somehow doubt it would be possible to restore its surface to what it once were, although someone might still be able to figure out what kind of ring this is.

AVATAR
	);
	set_weight(1);
	set_value(14);
	set_lore(
@AVATAR
%^GREEN%^This ring is probably of elven origin. The ornamentals probably once consisted of leaves and petals but little of that remains from what you can see. As you try to remember the lore about the elven rings only images of elven warriors comes to your mind.%^RESET%^

AVATAR
	);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-1);
	return 1;
}

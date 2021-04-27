#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gloves of the walker");
	set_id(({ "gloves" }));
	set_short("%^MAGENTA%^Gloves of the %^BLUE%^W%^MAGENTA%^a%^BLUE%^l%^MAGENTA%^k%^BLUE%^e%^MAGENTA%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A pair of greyish leather gloves with a symbol on them%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These gloves are in a light grey color. They are made out fine leather, designed to fit the hand of the individual user. On top of the hand,  there is a symbol of a %^MAGENTA%^hand pointing forward%^RESET%^%^BOLD%^%^BLACK%^ and a small %^YELLOW%^glowing inscription %^BOLD%^%^BLACK%^below it, marking these gloves as a gift bestowed upon those of the church of %^MAGENTA%^Shaundakul%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^I bless thee child, with the Gloves of the Walker%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
These gloves are often given to members of the church, that has risen to the level of Trailblazer above. They are ment to bind the small following of Shaundakul together, always letting eachother know that they have common goal. To spread the word of their lord whereever they may travel

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(3);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_attack_bonus(-3);
	return 1;
}

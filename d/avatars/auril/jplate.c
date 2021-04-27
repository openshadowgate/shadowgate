#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fire plate");
	set_id(({ "armor", "plate", "fire plate", "fullplate", "full plate" }));
	set_short("%^BOLD%^%^RED%^The %^BOLD%^%^RED%^In%^BOLD%^%^WHITE%^f%^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^rn%^BOLD%^%^RED%^o%^BOLD%^%^YELLOW%^'%^BOLD%^%^RED%^s %^BOLD%^%^RED%^Ca%^BOLD%^%^YELLOW%^re%^BOLD%^%^RED%^ss%^BOLD%^%^RESET%^");
	set_obvious_short("A suit of full plate");
	set_long(
@AVATAR
%^RESET%^%^RED%^This maginificant suit of full plate is made out of perfectly fitted plates of steel, interlocked with powerful metal joints and bonds. Padding is underneath the armor, making it more comfortable, though, as with all fullplate, it is cumbersome regardless. Underneath the plates darkned steel chain can be seen. The plates are coated in a sheen substance that reflects the light when touched. When worn the substance ignites, sending magical flames forth from the armor which do not harm the wearer.

AVATAR
	);
	set_weight(75);
	set_value(15000);
	set_lore(
@AVATAR
This was crafted by a Kossuthian follower who had always wanted to create the plate of his god. Using his finest tools and spending nearly a year in its crafting, this armor was created. Bulky and heavy, it's weight is created to add support though does not hinder movement much.

AVATAR
	);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^As "+ETO->query_cap_name()+" wears the armor, flames erupt and begin to dance around it.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^As you don the armor, flames rise up which dance all over it.");
	ETO->set_property("magic resistance",15);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^As "+ETO->query_cap_name()+" removes the armor the flames die down.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^As you remove the armor the flames die down.");
	ETO->set_property("magic resistance",-15);
	return 1;
}

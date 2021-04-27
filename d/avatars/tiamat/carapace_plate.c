#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("carapace breastplate");
	set_id(({ "carapace", "breastplate", "plate", "shell", "armor" }));
	set_short("%^BOLD%^%^RED%^Carapace Breastplate%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A shell-like breastplate%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a four-piece set or armor, made from the carefully prepared carapace of some large crustacean. The breastplate is matched by a piece of shell that also protects the back and two smaller components that guard the shoulders. Each piece has been carefully smoothed, reinforced on soft leather and joined with straps and rivets. The carapace is lightweight for its apparent strength.%^RESET%^

AVATAR
	);
	set_weight(40);
	set_value(2100);
	set_lore(
@AVATAR
%^RESET%^Carapace armor is fairly unusual, even for the undersea cultures of mer-folk and aquatic elves. However, there is occasional need for strong, waterproof armor. Carapace is a natural substance that grows as a excretions on a sea animal calcify. This armor was probably harvested from a giant crab or other ferocious crustacean. %^RESET%^


AVATAR
	);
	set_property("lore difficulty",15);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^The armor worn by "+ETOQCN+" fits together like their very own shell.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The pieces of natural armor fit into a highly protective casing.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^With some struggle, "+ETOQCN+" removes their carapace armor.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^With some shrugging and reaching, you remove the carapace armor.%^RESET%^");
	return 1;
}

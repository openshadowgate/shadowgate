#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shadow armor");
	set_id(({ "armor", "plate", "fullplate", "shadow armor" }));
	set_short("%^BOLD%^%^BLACK%^As%^RESET%^h%^BOLD%^%^BLACK%^en Fullplate%^RESET%^");
	set_obvious_short("%^RESET%^Ash colored fullplate%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a suit of fullplate armor, form fitting and gothic in style.  The plates are made of steel that have been brushed or antiqued in a nonreflective %^BOLD%^%^BLACK%^ashen polish%^RESET%^, that makes for near-perfect concealment in the darkness of the city.  Where the plates join together, an unusual %^MAGENTA%^soft fur%^RESET%^ pads the sounds of metal squeeking against metal.  The craftsmanship appears old in style, but the armor itself is still a living masterwork.%^RESET%^

AVATAR
	);
	set_weight(60);
	set_value(2300);
	set_lore(
@AVATAR
Ashen Fullplate has long been the traditional uniform for warrior clerics of Mask and their honor guard.  Few of the uninitiated know of their nature.  The unusual decorative style of the armor makes one more likely to blend in with with surroundings.  The padding made from the hide of the displacer beast silences the wearer's movements.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips on the metal armor quietly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You quietly slip on the metal armor.%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" manages to remove the armor with little sound.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the armor without a sound.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}

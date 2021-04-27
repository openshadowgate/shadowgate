#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("full plate");
	set_id(({ "battle's glory", "full plate", "plate", "armor" }));
	set_short("%^BOLD%^%^BLACK%^B%^RED%^a%^BLACK%^tt%^WHITE%^l%^BLACK%^e's G%^RED%^l%^BLACK%^ory%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^RESET%^burnished%^BOLD%^%^BLACK%^ set of full plate%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Sheets of burnished %^WHITE%^steel %^CYAN%^have been fitted together to form the basis of this elaborate suit of armor.  Decorated with an eye for function, none of the intricate decorations that depict the %^RED%^ebb%^CYAN%^-%^WHITE%^and%^CYAN%^-%^BOLD%^%^BLACK%^flow %^RESET%^%^CYAN%^of battle cause the plates to catch or grate upon each other.  Brushed with a %^BOLD%^%^BLACK%^darkening agent%^RESET%^%^CYAN%^, the steel has a lustrous sheen to it that catches faintly in the light and gleams with a %^WHITE%^dark silver%^CYAN%^ finish.  Atop each shoulder plate the symbol of the %^RED%^God of War %^CYAN%^can be seen.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(10000);
	set_lore(
@AVATAR
The suit of armor called "Battle's Glory" is actually several different sets of armor.  Made for a unit of elite knights and warriors sent by the temple to aid the southern empires during one of the many wars.  The warriors were known for their skill and their tenacity and are quoted as yelling "for the glory of battle".  In time, due to the uniqueness of their armor, they became recognized as the "Battle's Glory".

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You settle the plates of armor upon your shoulders and feel years of experience flood your mind. %^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You draw the armor off and feel the heat of battle drain away.%^RESET%^");
	return 1;
}


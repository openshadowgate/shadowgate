#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RED%^amulet of blood%^RESET%^");
	set_id(({ "amulet", "necklace", "amulet of blood", " crystal amulet", "item" }));
	set_short("%^RESET%^%^RED%^amulet of blood%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^crystal amulet%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Suspended from a thin silver chain, a small crystal hangs. It is shaped like a teardrop and is murky. The workmanship of the amulet is amazing, and it is obviously the creation of a master. The cloudy crystal seems to vibrate softly creating a low hum%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
%^CYAN%^%^BOLD%^A creation of a legendary demon hunter, the necklace of blood was created to attempt to protect the wearer from the adverse effects of the darker planes and lairs of her hunts. She had the necklaces made by a gnomish jeweler, who made several and had them blessed by a member of a legendary group of champions of Light.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^The crystal on "+ETOQCN+"%^RESET%^%^RED%^'s amulet fills with blood%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^The crystal on the amulet suddenly darkens as if filled with blood%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+"%^RESET%^%^RED%^'s amulet returns to simple crystal%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^the amulet becomes simple crystal again%^RESET%^");
	return 1;
}


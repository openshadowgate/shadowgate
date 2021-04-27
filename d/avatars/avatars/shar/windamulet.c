#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("amulet");
	set_id(({ "amulet", "amulet of the winds", "winds" }));
	set_short("%^BOLD%^%^CYAN%^Amulet of the Winds%^RESET%^");
	set_obvious_short("An amulet");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^An odd amulet rests on a crystal quartz chain.  The amulet itself is hard to describe.  It appears as if it is made of some kind of gemstone, though there is no weight to it.  One is able to easily pass their hand through the swirling blue "gemstone".  Upon a closer look, one notices etched into the links of the crystal quartz chain are some rune.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^Where ever you travel, know that the Queen of the Air will always be close to your heart.  For nothing can stop the flow of her domain.

AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
The Amulet of the Winds was first fashioned by Eldetharn the Siricco, a wandering desert priest of Akadi.  The priest wished for a way to carry a portion of his Goddess' domain with him where ever he traveled.  Using a now lost ritual he was able to shape and semi solidify a protion of the air into a gem, which he then bound to a crystal quartz chain.  Though the Sirricco of Akadi perished in a gruesome battle against a horde of xorn, somehow his amulet survived him.  Some say that Akadi herself enchanted the amulet with the power to merge with the air and reveal itself only to the most worthy.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s hair is ruffled by a gentle breeze",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^You feel the caress of a cool breeze against your skin.");
	ETO->add_attack_bonus(2);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^The breeze about you fades away.");
	ETO->add_attack_bonus(-2);
	return 1;
}

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("sapphire ring");
	set_id(({ "ring", "sapphire ring" }));
	set_short("%^BLUE%^a pale %^BOLD%^%^CYAN%^sapphire%^RESET%^%^BLUE%^ ring%^RESET%^");
	set_obvious_short("%^BLUE%^a pale %^BOLD%^%^CYAN%^sapphire%^RESET%^%^BLUE%^ ring%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^This lovely %^BOLD%^%^CYAN%^sapphire ring%^RESET%^%^BLUE%^ is made from a perfectly clear stone that is almost as pale as a %^WHITE%^diamond %^BLUE%^and glitters brilliantly with an inner %^BOLD%^%^CYAN%^luster%^RESET%^%^BLUE%^ that seems magical with its intensity.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
There are many legends of the blue diamonds said to hold incredible powers.  And some attribute the white sapphires as the source of these legends.  Made by a wizard over a thousand years ago, they are known for their ability to protect and sustain their wearers.  Their beautiful coloration is prized by many simply for fashion's sake, though the enchantments are rumored to be a great prize as well.

AVATAR
	);
	set_property("lore difficulty",15);
	set("strbonus",1);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",1);
}



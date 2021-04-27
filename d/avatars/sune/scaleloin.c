#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("a %^ORANGE%^loincloth%^RESET%^ fashioned from tiny %^ORANGE%^s%^BLUE%^c%^ORANGE%^a%^BLUE%^l%^ORANGE%^e%^BLUE%^s%^RESET%^");
	set_id(({ "loincloth", "scaley", "scaley loincloth", "loin" }));
	set_short("%^RESET%^%^ORANGE%^S%^BLUE%^c%^ORANGE%^a%^BLUE%^l%^ORANGE%^e%^BLUE%^y %^ORANGE%^loincloth%^RESET%^");
	set_long(
@AVATAR
This loincloth seems to be fashioned from very tiny %^ORANGE%^s%^BLUE%^c%^ORANGE%^a%^BLUE%^l%^ORANGE%^e%^BLUE%^s%^RESET%^ sewn into a %^ORANGE%^leather%^RESET%^ backing. The scales are %^BOLD%^%^BLUE%^worn%^RESET%^ and %^GREEN%^pitted%^RESET%^ but still very capable of providing some protection to one's nether regions. The workmanship seems to have once been very fine, and it makes you wonder where this may have come from.

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
The scales used in this loincloth are actually the shed off remnants of wyrmling %^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^ and %^ORANGE%^co%^BOLD%^p%^RESET%^%^ORANGE%^per%^GREEN%^ dragons%^RESET%^, hence their tiny appearance. Someone must have gathered them and thought that they would offer some tiny amount of protection.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(1);
	set_property("enchantment",1);
}



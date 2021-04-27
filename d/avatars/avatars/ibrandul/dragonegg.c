#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^odd b%^RESET%^l%^BLACK%^%^BOLD%^ack eg%^RESET%^g%^BLACK%^%^BOLD%^g%^RESET%^");
	set_id(({ "egg", "dragon egg" }));
	set_short("%^BLACK%^%^BOLD%^odd b%^RESET%^l%^BLACK%^%^BOLD%^ack e%^RESET%^g%^BLACK%^%^BOLD%^g%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^odd b%^RESET%^l%^BLACK%^%^BOLD%^ack e%^RESET%^g%^BLACK%^%^BOLD%^g%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^This egg, weighing in at around a pound, has an elongated ovoid shape and a hard, stony shell that seems almost unbreakable. The entire surface of the egg is black, with %^RESET%^veins of dark gray%^BLACK%^%^BOLD%^ running through it.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^BLACK%^%^BOLD%^The egg of a black dragon is a very valuable, dangerous, and foolish thing to have, for where there is an egg, there is a mother. But the mother wouldnt leave the egg alone, so either it's been stolen, or the mother killed. The hatchling will only emerge when it's ready...%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
}
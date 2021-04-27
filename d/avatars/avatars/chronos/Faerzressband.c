#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "band" }));
	set_short("%^RESET%^%^MAGENTA%^Fae%^BOLD%^%^BLACK%^rzr%^RESET%^%^MAGENTA%^ess%^BOLD%^%^BLACK%^ Band%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A softly %^RESET%^%^MAGENTA%^glowing%^RESET%^ ring");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a small chunk of the ore %^RESET%^%^MAGENTA%^Faerzress%^BOLD%^%^BLACK%^ carefully sculpted into a ring. The ring itself has a careful etching of some manner of elaborate %^RED%^swirls, loops%^BLACK%^ and such. Although it %^MAGENTA%^glows%^BLACK%^ softly it has the tendancy to absorb the light around it and it %^RESET%^%^RED%^warm%^BOLD%^%^BLACK%^ to the touch at all times.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR
Legends tell of a tribe of Orcs that spent far too much time in close proximity of the ore Faerzress. It some how mutated them giving them a higher intellect and a tendancy to be more careful than a standard orc. These rings were usually awarded to significant commanders of this War Parties and only after many succesful raids.

AVATAR
	);
	set_property("lore difficulty",15);
}

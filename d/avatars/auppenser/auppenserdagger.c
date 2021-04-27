#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("auppenserdagger");
	set_id(({ "dagger" }));
	set_short("%^YELLOW%^Auppenser's%^RESET%^%^BOLD%^%^BLACK%^ Dagger%^RESET%^");
	set_obvious_short("%^YELLOW%^Auppenser's%^RESET%^%^BOLD%^%^BLACK%^ Dagger%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The blade of this dagger is made from obsidian and is pitch black with a glassy sheen as a result.  The 4" grip is made of %^YELLOW%^bronze%^BLACK%^ wrapped in black leather. The pommel has a %^YELLOW%^bronze setting%^BLACK%^ in which an %^RESET%^%^CYAN%^eye%^BOLD%^%^BLACK%^ made from %^RESET%^diamonds%^BOLD%^%^BLACK%^ for the %^RESET%^white%^BOLD%^%^BLACK%^ of the eye, %^RESET%^%^CYAN%^ light blue topaz%^BOLD%^%^BLACK%^ for the iris, and %^CYAN%^aquamarine%^BLACK%^ for the pupils is set.  The 7" blade is exceptionally sharp and a deep %^RED%^blood groove%^BLACK%^ runs down the center of the blade almost to its point.  This weapon is %^RESET%^finely crafted%^BLUE%^, beautiful, %^BOLD%^%^BLACK%^and %^RED%^dangerous looking.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Auppenser was never in need of physical weapons even when he was mortal, due to his fantastic gifts of the mind.  However, he once admired a set of daggers carried by a traveling mercanary and had a similar set made for mere decoration in his home.  Upon his death and subsequent ascension, he had his precious daggers enchanted by Mystra.  He wears them on his person and is never without them.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("small");
	set_size(small);
	set_wc(3,4);
	set_large_wc(3,4);
	set_property("enchantment",30);
	set_ac(0);
}



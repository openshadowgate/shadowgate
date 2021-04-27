#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("The Infant");
	set_id(({ "dagger", "knife", "artifact", "The Infant" }));
	set_short("%^BOLD%^The Infant%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Snowflake Obsidian Dagger%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^The blade of this dagger is made from snowflake obsidian.  This material is glassy and black like regular obsidian, but is softer and fractures more easily, leaving a snowflake pattern.  So this dagger is either strictly ornamental or the dark aura that surrounds it infer a magical use of some kind.  The black, glassy blade has a nine-tailed scourge etched into its base on either side.  The blade has no blood groove as many blades don't, but it is serrated on one side.  The blade has a toothy look reminding you of the jaw of some sort of monster.  The hilt is made of %^RESET%^ivory%^BOLD%^%^BLACK%^ and is carved in the likeness of an upside down %^RESET%^infant%^BOLD%^%^BLACK%^.  The %^RESET%^infant%^BOLD%^%^BLACK%^ is nude with its legs crossed so the gender cannot be determined.  Its eyes are closed but it does not look asleep, it looks dead.  The blade rises out of its head and at its feet is the pommel of the hilt, a %^RED%^blood red, flawless garnet.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(15000);
	set_lore(
@AVATAR
%^BOLD%^This appears to be the artifact called The Infant.  It was rumored to have been created by Loviatar's Arch-mage, Hollister. Its express purpose is to be used by a powerful walock creature chosen by Loviatar, binding him to Loviatar's will.  The dagger removes all free will from the bearer of it.  It is also rumored that this dagger is but one component used in a ritual making the warlock so powerful that no mortal can stand against him, forever making him Loviatar's Champion.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,8);
	set_large_wc(2,6);
	set_property("enchantment",5);
	set_ac(0);
}



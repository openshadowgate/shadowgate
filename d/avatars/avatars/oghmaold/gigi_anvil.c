#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("anvil of doom");
	set_id(({ "anvil", "iron anvil", "huge anvil", "anvil of doom", "huge iron anvil" }));
	set_short("%^BOLD%^%^RED%^Anvil %^WHITE%^of %^BLACK%^Doom%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^RESET%^%^RED%^huge %^BOLD%^%^BLACK%^iron anvil %^WHITE%^on an %^RESET%^%^ORANGE%^oak base%^RESET%^");
	set_long(
@AVATAR
This is a large %^BOLD%^%^BLACK%^iron anvil %^RESET%^atop an %^ORANGE%^oak base%^RESET%^.  It is shaped like an ordinary smithy's anvil, but much more skill and time have been put into crafting it.  It is covered in intricate, angular %^BOLD%^%^RED%^Dwarven runes %^RESET%^that pulsate a %^RESET%^%^RED%^dark red light%^RESET%^.  Fanciful designs of %^BOLD%^%^BLACK%^black dragons %^RESET%^have been carved into the base of the anvil, furthering the deep, %^BOLD%^%^BLACK%^dark %^RESET%^look.

AVATAR
	);
	set_weight(100000);
	set_value(1000000);
	set_lore(
@AVATAR
This is a dwarven anvil of doom.  It is rumored that they were crafted eons ago by dwarf runesmiths in order to aid them in forging their legendary magical items.  There were only thirteen of these made originally, and of that only seven are reported to exist now.  This one in particular was owned by the Blackhammer clan for ages on end until it was taken in a drow attack roundabout two hundred years ago.  After that nobody knows precisely what happened to it.

AVATAR
	);
	set_property("lore difficulty",0);
}
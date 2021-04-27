#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("anvil of doom");
	set_id(({ "anvil", "anvil of doom" }));
	set_short("%^BOLD%^%^RED%^Anvil %^WHITE%^of %^BLACK%^Doom%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A huge %^BOLD%^%^RED%^rune etched %^BLACK%^iron anvil %^WHITE%^on a %^RESET%^%^ORANGE%^oak base%^RESET%^");
	set_long(
@AVATAR
This is large %^BOLD%^%^BLACK%^iron anvil %^RESET%^atop an %^RESET%^%^ORANGE%^oak base%^RESET%^.  It is shaped like an ordinary smithy's anvil, but much more skill has been put into crafting it.  It is covered in intricate, angular %^BOLD%^%^RED%^Dwarven runes %^RESET%^that pulsate a %^RESET%^%^RED%^dark red light%^RESET%^.  Fanciful designs of %^BOLD%^%^BLACK%^black dragons %^RESET%^have been carved into the base of the anvil, furthering the deep, dark look.

AVATAR
	);
	set_weight(50);
	set_value(10000);
	set_property("lore difficulty",0);
    set_lore("This is a dwarven anvil of doom.  It is rumored "+
    "they were crafted eons ago by dwarf runesmiths in order to "+
    "aid them in crafting their legendary magic items.  There "+
    "were only thirteen of these made originally, and of that "+
    "only seven are reported to exist now.  This one in particular "+
    "was owned by the Blackhammer clan for ages on end until it "+
    "was mysteriously taken in a drow attack two hundred "+
    "years ago.  After that nobody knows precisely what happened "+
    "to it.");
}
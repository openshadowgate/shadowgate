#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("iron ring");
	set_id(({ "ring", "iron ring" }));
	set_short("%^BOLD%^%^BLACK%^r%^CYAN%^u%^BLACK%^nic r%^RED%^i%^BLACK%^ng of i%^BLUE%^r%^BLACK%^on%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a small iron ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a thick band of iron meant for a small finger, or a small person's big finger.  Shaped in a hexigon each side holds a different dwarven rune upon it, though without knowing dwarven it would be hard to %^RED%^read%^BLACK%^ the runes and know its purpose.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^* %^RED%^Dwarven%^BLACK%^ *
%^BOLD%^%^BLACK%^* %^RED%^Friend%^BLACK%^ *
%^BOLD%^%^BLACK%^* %^RED%^Welcome%^BLACK%^ *
%^BOLD%^%^BLACK%^* %^RED%^Within%^BLACK%^ *
%^BOLD%^%^BLACK%^* %^RED%^Mead%^BLACK%^ *
%^BOLD%^%^BLACK%^* %^RED%^Hall%^BLACK%^ *
%^RESET%^

AVATAR
	);
     set("langage","dwarvish");	set_weight(1);
	set_value(50);
	set_lore(
@AVATAR
These rings are often given out by the dwarven people to those who they owe gratitude or a debt to.  These then can be presented to other dwarves to show the person is a friend and can be trusted, or at least tolerated, since dwarves don't much care for outsiders.  The runes however tell the tale.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",0);
}



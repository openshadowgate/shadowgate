#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("turtle shell shield");
	set_id(({ "shield" }));
	set_short("%^RESET%^%^GREEN%^T%^BOLD%^u%^RESET%^%^GREEN%^rtl%^BOLD%^e%^RESET%^%^GREEN%^ Shield%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A turtle shell shield%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This is a shield that has been masterfully crafted out of the shell of a huge snapping turtle.  Though the outer shell is rough and scaly, it has been polished and lacquered into an impressive %^BOLD%^%^GREEN%^shine%^RESET%^%^GREEN%^.  The shell is large enough to protect the hand and most of the forearm.  It is worn by slipping the arm through and gripping two oiled, waterproof straps.  The inside of the shell has been reinforced with leather, keeping it lightweight but still very durable.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(2100);
	set_lore(
@AVATAR
%^RESET%^Snapping turtles are a common problem in marshy areas, but the largest ones grow in the deadly swamps on the island of Laerad.  On the occasion that one of these spectacular beasts are trapped or killed, they are often made into an impressive soup served in its own giant shell.  Following this ceremony, the shells are made into shields in Asgard, and often receive enchantments.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("shield");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
}



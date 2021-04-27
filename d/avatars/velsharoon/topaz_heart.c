#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("topaz heart");
	set_id(({ "gem", "topaz", "heart", "topaz heart" }));
	set_short("%^RESET%^%^ORANGE%^To%^BOLD%^p%^RESET%^%^ORANGE%^az %^BOLD%^%^RED%^H%^RESET%^%^RED%^e%^MAGENTA%^a%^RED%^r%^BOLD%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a large %^RED%^heart%^BLUE%^-shaped %^CYAN%^gemstone%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This gem is almost the size of a halflings head! It is in the shape of a %^RESET%^%^GREEN%^dragons%^GREEN%^ scale%^BOLD%^%^BLUE%^ and was once imbedded in a golem's chest. The %^RESET%^%^ORANGE%^to%^BOLD%^p%^RESET%^%^ORANGE%^az%^BOLD%^%^BLUE%^ has lost it's eldritch energy but still seems like it would be worth a small fortune.%^RESET%^

AVATAR
	);
	set_weight(45);
	set_value(10000);
	set_lore(
@AVATAR
This topaz was once the "heart" of a topaz golem created by Kiirolathnaleter, The Incarnum, a great wyrm topaz dragon. The gemstone once contained the golems magical functions and other powerful spells that powered it. The gem itself is extremely rare and definately difficult to find.

AVATAR
	);
	set_property("lore difficulty",14);
}

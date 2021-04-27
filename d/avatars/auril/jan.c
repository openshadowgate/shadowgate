#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("janblade");
	set_id(({ "sword", "longsword", "long sword", "family sword" }));
	set_short("%^BOLD%^%^WHITE%^A silver bladed longsword%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^Broenil's %^RESET%^%^MAGENTA%^helping hand%^RESET%^");

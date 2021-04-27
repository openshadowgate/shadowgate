#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Monocle");
	set_id(({ "monocle", "eyepiece", "lens" }));
	set_short("%^BOLD%^%^WHITE%^A %^YELLOW%^gold-rimmed %^CYAN%^monocle%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^YELLOW%^gold-rimmed %^CYAN%^monocle%^RESET%^");
	set_long(
@AVATAR
This is a small, %^MAGENTA%^fancy%^RESET%^ monocle. A rim of shiny %^BOLD%^%^YELLOW%^gold%^RESET%^ encircles a %^BOLD%^%^CYAN%^glass lens%^RESET%^ that has been buffed to an impeccable %^BOLD%^%^BLUE%^smoothness%^RESET%^. The monocle is attached to a thin %^BOLD%^%^YELLOW%^gold chain%^RESET%^ that ends in a %^BOLD%^%^WHITE%^clip%^RESET%^ as to be attached to a jacket, robe, or other such clothing. It is obvious this piece of %^BOLD%^%^RED%^jewelry%^RESET%^ favors looks over funcionality.

AVATAR
	);
	set_weight(1);
	set_value(50);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}



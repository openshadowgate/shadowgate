#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^A small %^BLUE%^teardrop%^RESET%^");
	set_id(({ "teardrop", "Teardrop", "bottle", "Bottle", "vial", "Vial" }));
	set_short("%^RESET%^%^BLUE%^Ist%^CYAN%^i%^BLUE%^sh%^CYAN%^i%^BLUE%^a's %^BOLD%^%^BLUE%^tears%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A small %^BLUE%^teardrop%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a small bottle made into the shape of a %^BOLD%^%^BLUE%^teardrop%^RESET%^%^CYAN%^, it is made from a perfect %^BOLD%^%^WHITE%^crystal%^RESET%^%^CYAN%^. It has no opening and it is filled with a perfectly clear liquid.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
}
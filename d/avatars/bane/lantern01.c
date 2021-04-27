#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^A jeweled, %^RESET%^%^WHITE%^silver %^BOLD%^%^BLUE%^lantern%^RESET%^");
	set_id(({ "lantern", "Lantern" }));
	set_short("%^BOLD%^%^BLUE%^M%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^o%^CYAN%^n%^BOLD%^%^WHITE%^l%^CYAN%^i%^WHITE%^ght%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A jeweled %^RESET%^%^WHITE%^silver %^BOLD%^%^BLUE%^lantern%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This is a %^BOLD%^%^BLUE%^jeweled%^BOLD%^%^YELLOW%^, %^BOLD%^%^WHITE%^silver %^BOLD%^%^YELLOW%^bullseye lantern. %^BOLD%^%^BLUE%^Sapphires %^BOLD%^%^YELLOW%^ring the bottom and top of the lantern, %^BOLD%^%^WHITE%^silver %^BOLD%^%^YELLOW%^lining around each gem and making up the base form of the lantern. Two %^RESET%^%^WHITE%^silver %^BOLD%^%^YELLOW%^eyes surronded by seven %^RESET%^%^WHITE%^stars %^BOLD%^%^YELLOW%^cover each side of the lantern.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_property("lore difficulty",0);
}
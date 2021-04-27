#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^WHITE%^v%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^CYAN%^l of sw%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^%^CYAN%^rli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^BOLD%^%^CYAN%^g w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_id(({ "water", "vial" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^v%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^CYAN%^l of sw%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^%^CYAN%^rli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^BOLD%^%^CYAN%^g w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^v%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^CYAN%^l of sw%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^%^CYAN%^rli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^BOLD%^%^CYAN%^g w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^this small %^RESET%^%^WHITE%^glass vial %^RESET%^%^CYAN%^contains a neasure of water that seems to s%^RESET%^%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ir%^RESET%^%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^ and d%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^n%^RESET%^%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^e in the confines of its container. The stopper is a %^RESET%^%^BOLD%^%^WHITE%^silver statue %^RESET%^%^CYAN%^of a dragon in mid flight%^RESET%^%^WHITE%^

AVATAR
	);
	set_weight(1);
	set_value(10);
}
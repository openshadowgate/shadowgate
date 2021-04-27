#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Kestrel");
	set_id(({ "boomerang", "kestrel" }));
	set_short("%^RED%^K%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^s%^BLUE%^t%^RESET%^%^BLUE%^r%^RED%^e%^BOLD%^%^WHITE%^l%^RESET%^");
	set_obvious_short("%^ORANGE%^A %^RED%^c%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^l%^BLUE%^o%^BOLD%^r%^RESET%^%^RED%^f%^BOLD%^%^WHITE%^ul %^RESET%^%^ORANGE%^boomerang%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This curving V shaped weapon is remarkably light, carved of fine grained darkwood and laquered to a shiny finish. Painted skillfully along the top and bottom to resemble a  %^RED%^c%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^l%^BLUE%^o%^BOLD%^r%^RESET%^%^RED%^f%^BOLD%^%^WHITE%^ul %^RESET%^%^ORANGE%^bird of prey, awash in %^RED%^reds%^ORANGE%^, %^BOLD%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^s%^RESET%^%^ORANGE%^ and %^RED%^c%^ORANGE%^inn%^RED%^a%^ORANGE%^m%^RED%^o%^ORANGE%^n hues. The "wings" of the Boomerang have been carefully sharpened at their tapered edges, and serrated with featherlike pinions. Perfectly balanced, this weapon looks like it was made to fly. 

AVATAR
	);
	set_weight(1);
	set_value(5000);

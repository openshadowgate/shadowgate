#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^WHITE%^Lar%^RESET%^%^CYAN%^g%^RESET%^%^BOLD%^%^WHITE%^e gla%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^WHITE%^s bo%^RESET%^%^BOLD%^%^CYAN%^t%^RESET%^%^BOLD%^%^WHITE%^tle%^RESET%^");
	set_id(({ "bottle", "glass bottle", "large glass bottle" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^B%^RESET%^%^CYAN%^o%^RESET%^%^BOLD%^%^WHITE%^ttle for C%^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^%^WHITE%^ou%^RESET%^%^BOLD%^%^CYAN%^d%^RESET%^%^BOLD%^%^WHITE%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^Lar%^RESET%^%^CYAN%^g%^RESET%^%^BOLD%^%^WHITE%^e gla%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^WHITE%^s bo%^RESET%^%^BOLD%^%^CYAN%^t%^RESET%^%^BOLD%^%^WHITE%^tle%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This bottle is large, and spun of perfect glass. There isnt anything in it right now, but there is a large %^RESET%^%^ORANGE%^cork stopper %^RESET%^%^CYAN%^ready to seal the bottle once something suitable has been placed inside. However, the neck is rather small.. It would have to be a %^RESET%^%^BOLD%^%^CYAN%^liquid %^RESET%^%^CYAN%^or %^RESET%^%^BOLD%^%^MAGENTA%^gas %^RESET%^%^CYAN%^to even fit into it. %^RESET%^

AVATAR
	);
	set_weight(30);
	set_value(0);
	set_lore(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^A bottle made by Ibby to trap his student when he realized she no longer needed his teachings... %^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
}
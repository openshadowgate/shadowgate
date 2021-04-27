#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a rock");
	set_id(({ "ore", "rock" }));
	set_short("%^RESET%^%^CYAN%^A sample of %^BOLD%^%^BLACK%^m%^RESET%^it%^BOLD%^h%^RESET%^ri%^BOLD%^%^BLACK%^l %^RESET%^o%^BOLD%^r%^RESET%^e%^RESET%^");
	set_obvious_short("%^RESET%^A large sp%^BOLD%^a%^RESET%^rk%^BOLD%^%^BLACK%^l%^RESET%^i%^BOLD%^n%^RESET%^g rock%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This rather large rock looks as though it's been hewn from deep beneath the earth.  There are strange %^BOLD%^%^BLACK%^s%^RESET%^il%^BOLD%^v%^RESET%^er%^BOLD%^%^BLACK%^y %^RESET%^%^CY"
	"AN%^segments to it, veins of what looks like quicksilver running throughout the sample.%^RESET%^
"
	);
	set_value(7500);
	set_weight(50);
	set_lore("%^RESET%^%^CYAN%^Mithril is often prized by masters of the anvil, both for its combination of strength and lack of weight, and for the ease with which the metal can be enchanted.  Seams of mithril ore"
	" are rare, and to trespass on mine claims has often led to rifts in the dwarven community (and are usually the basis for ancestral clan feuds).%^RESET%^
"
	);
    set_property("lore difficulty",10);
}

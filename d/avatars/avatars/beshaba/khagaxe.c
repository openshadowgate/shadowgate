#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe";

void create(){
	::create();
	set_name("axe");
	set_id(({ "axe", "large axe", "glyph-bound axe" }));
	set_short("%^RESET%^%^RED%^g%^BOLD%^l%^MAGENTA%^y%^RED%^p%^RESET%^%^RED%^h-b%^BOLD%^o%^MAGENTA%^u%^RED%^n%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^a%^RESET%^x%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^e%^BOLD%^e%^MAGENTA%^r%^RED%^i%^RESET%^%^RED%^e %^ORANGE%^makeshift %^BOLD%^%^BLACK%^a%^RESET%^x%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Crudely made, this is little more than a wedge of s%^RESET%^c%^BOLD%^r%^RESET%^a%^BOLD%^%^BLACK%^p m%^RESET%^e%^BOLD%^t%^RESET%^a%^BOLD%^%^BLACK%^l mounted on a twisted oaken stock. T"
	"here are strange %^RESET%^%^RED%^s%^BOLD%^i%^MAGENTA%^gi%^RED%^l%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^g%^BOLD%^l%^MAGENTA%^yp%^RED%^h%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^scrawled along "
	"the blade, picked out in an unknown %^RESET%^%^CYAN%^i%^BOLD%^c%^GREEN%^h%^CYAN%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^, which seem to waver and twist before your eyes.%^RESET%^
"
	);
	set_value(200);
	set_lore("%^RESET%^%^CYAN%^Though this axe is little more than an improvised weapon of opportunity, the sigils seem to give it an unnatural strength and power. It is likely a dark blessing bestowed by a shaman "
	"among the orcish clan.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_property("enchantment",3);
}




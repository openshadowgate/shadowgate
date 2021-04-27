#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe";

void create(){
	::create();
	set_name("an axe");
	set_id(({ "axe", "twisted axe", "harbinger of woe" }));
	set_short("%^BOLD%^%^RED%^H%^BLACK%^arb%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^nger %^RESET%^o%^BOLD%^%^BLACK%^f %^RED%^W%^RESET%^%^MAGENTA%^oe%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a s%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ster a%^RESET%^%^RED%^x%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Crudely made, this is little more than a wedge of s%^RESET%^c%^BOLD%^r%^RESET%^a%^BOLD%^%^BLACK%^p m%^RESET%^e%^BOLD%^t%^RESET%^a%^BOLD%^%^BLACK%^l mounted on a twisted oaken stock. T"
	"here are strange %^RESET%^%^RED%^si%^BOLD%^gi%^RESET%^%^RED%^ls %^BOLD%^%^BLACK%^along the blade picked out in an unknown %^RESET%^%^MAGENTA%^ichor%^BOLD%^%^BLACK%^, though, which seem to move and twi"
	"st before your eyes.%^RESET%^
"
	);
	set_value(1500);
	set_lore("%^BOLD%^%^CYAN%^Though this axe is little more than an improvised weapon of opportunity, the sigils seem to give an unnatural strength to it. It is likely a dark blessing bestowed by a dark shaman amo"
	"ng the orcish clan.%^RESET%^
"
	);
    set_property("lore difficulty",15);
	set_property("enchantment",1);
}




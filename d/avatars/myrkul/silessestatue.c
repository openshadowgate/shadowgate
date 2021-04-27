#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("statue");
	set_id(({ "statue" }));
	set_short("%^BOLD%^%^GREEN%^Statue of %^YELLOW%^S%^RESET%^%^ORANGE%^i%^YELLOW%^l%^RESET%^%^ORANGE%^e%^YELLOW%^s%^RESET%^%^ORANGE%^s%^YELLOW%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^Statue of an %^YELLOW%^e%^RESET%^%^ORANGE%^l%^YELLOW%^f%^RESET%^");
	set_long("This is a highly ornamented and well crafted statue of an %^YELLOW%^elf%^RESET%^. The statue is made out of some kind of %^RESET%^%^CYAN%^crystal%^RESET%^. The elf is female, rather %^CYAN%^willowy%^R"
	"ESET%^ with a single %^BOLD%^%^BLACK%^black l%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^tus%^RESET%^ tucked into her %^RED%^l%^BOLD%^o%^RESET%^%^RED%^ng au%^BOLD%^b%^RESET%^%^RED%^urn hair%^RESET%^.
"
	);
	set_value(10000);
	set_weight(1);
	set_lore("%^RESET%^%^MAGENTA%^This is a tracking crystal attuned by a master psychic. The %^CYAN%^illithid%^MAGENTA%^ are known to use these to track their enemies across long distances. These are terrible %^RE"
	"D%^weapons%^MAGENTA%^ made of priceless crystals for the most dangerous of foes.%^RESET%^
"
	);
    set_property("lore difficulty",20);
}

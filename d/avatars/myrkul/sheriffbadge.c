#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("sheriffbadge");
	set_id(({ "badge", "sheriffs badge" }));
	set_short("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^eriffs B%^RESET%^%^CYAN%^a%^BOLD%^dge of %^YELLOW%^Torm%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^eriffs B%^RESET%^%^CYAN%^a%^BOLD%^dge of %^YELLOW%^Torm%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This badge is made of %^YELLOW%^gold%^RESET%^%^CYAN%^, and shaped into the symbol of %^YELLOW%^Torm%^RESET%^%^CYAN%^. The image is of a %^BOLD%^%^WHITE%^masted ship%^RESET%^%^CYAN%^ w"
	"hich rests in the %^BOLD%^%^BLUE%^watery foreground%^RESET%^%^CYAN%^ of a busy %^RESET%^%^ORANGE%^city harbor%^CYAN%^.  At the edge of the water, towering over the city, is the majestic silhouette of "
	"a male %^YELLOW%^statue%^RESET%^%^CYAN%^. In his outstretched hand he holds a %^BOLD%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky is a %^BOLD%^%^WHITE%^c"
	"rescent moon%^RESET%^%^CYAN%^ flanked by %^BOLD%^five glittering stars%^RESET%^%^CYAN%^. Small %^BOLD%^%^RED%^ruby gemstones%^RESET%^%^CYAN%^ completes this puzzle adding colors at the right places.%^"
	"RESET%^
"	);
	set_value(1000);
	set_lore("%^YELLOW%^This is the badge of the Sheriff of Torm. This one was given to Zathery of Tyr for his services to the city of Torm. It grants the power of the King to the bearer to make any arrest in the n"
	"ame of the law in the city.%^RESET%^
"	);
	set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",0);
}




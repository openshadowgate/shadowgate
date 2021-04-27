#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("weddingringtorm");
	set_id(({ "ring", "wedding ring" }));
	set_short("%^YELLOW%^W%^RESET%^%^ORANGE%^e%^YELLOW%^d%^RESET%^%^ORANGE%^d%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RED%^ Ring%^RESET%^%^RED%^ of %^YELLOW%^T%^RESET%^%^ORANGE%^o%^YELLOW%^rms %^RED%^F%^RESET%^%^RED%^i%^BOLD%^rst L%^RESET%^%^RED%^a%^BOLD%^dy%^RESET%^");
	set_obvious_short("%^YELLOW%^W%^RESET%^%^ORANGE%^e%^YELLOW%^d%^RESET%^%^ORANGE%^d%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^g%^RED%^ Ring%^RESET%^%^RED%^ of %^YELLOW%^T%^RESET%^%^ORANGE%^o%^YELLOW%^rms %^RED%^F%^RESET%^%^RED%^i%^BOLD%^rst L%^RESET%^%^RED%^a%^BOLD%^dy%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This ring is made of %^YELLOW%^gold%^RESET%^%^CYAN%^ and has an enormous %^BOLD%^%^WHITE%^diamond%^RESET%^%^CYAN%^ worth a fortune. The %^BOLD%^%^WHITE%^diamond%^RESET%^%^CYAN%^ is fl"
	"anked with %^BOLD%^%^RED%^delicate r%^RESET%^%^RED%^u%^BOLD%^bies%^RESET%^%^CYAN%^. The metal of the ring bears the symbol of %^YELLOW%^Torm%^RESET%^%^CYAN%^. The image is of a %^BOLD%^%^WHITE%^masted"
	" ship%^RESET%^%^CYAN%^ which rests in the %^BOLD%^%^BLUE%^watery foreground%^RESET%^%^CYAN%^ of a busy %^RESET%^%^ORANGE%^city harbor%^CYAN%^.  At the edge of the water, towering over the city, is the"
	" majestic silhouette of a male %^YELLOW%^statue%^RESET%^%^CYAN%^. In his outstretched hand he holds a %^BOLD%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky"
	" is a %^BOLD%^%^WHITE%^crescent moon%^RESET%^%^CYAN%^ flanked by %^BOLD%^five glittering stars%^RESET%^%^CYAN%^. Small %^BOLD%^%^RED%^ruby gemstones%^RESET%^%^CYAN%^ completes this puzzle adding color"
	"s at the right places.%^RESET%^
"	);
	set_value(50000);
	set_lore("%^BOLD%^%^RED%^This ring is the wedding ring of Umzazilil, the Vizier of Torm given to the Lady Adea of Kossuth. The Lady had put on an enormous festival in the name of Kossuth, and the vizier accepte"
	"d a proposal to cement the relationship. %^RESET%^
"	);
	set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",0);
}




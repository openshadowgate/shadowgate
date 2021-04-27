#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("spiderdust");
	set_id(({ "dust", "spider dust", "bag" }));
	set_short("%^BOLD%^%^BLACK%^S%^WHITE%^p%^BLACK%^i%^WHITE%^d%^BLACK%^e%^WHITE%^r %^BLACK%^D%^WHITE%^u%^BLACK%^s%^WHITE%^t%^RESET%^");
	set_obvious_short("%^CYAN%^a small, sticky bag%^RESET%^");
	set_long("%^ORANGE%^This is a small leather bag about the size of your fist filled with a grainy powder-like substance.  The outside of the bag is very %^BOLD%^%^WHITE%^sticky %^RESET%^%^ORANGE%^and tries very "
	"hard to stay in your hands even as you let go.  The bag is tied at the top with a short strand of %^BOLD%^golden %^RESET%^%^ORANGE%^twine.%^RESET%^
"
	);
	set_value(1000);
	set_weight(3);
	set_lore("%^ORANGE%^The very rare %^BOLD%^%^BLACK%^Orb Spider %^RESET%^%^ORANGE%^from the remote reaches of the %^BOLD%^Barrier Mountains %^RESET%^%^ORANGE%^reaches an astounding 10 inches in body diameter with"
	" a length (front legs to hind legs) of up to 2 and 1/2 feet!  The %^RED%^webs %^ORANGE%^created by these creatures are extremely strong and have been known to trap strong animals such as bulls and hor"
	"ses within their sticky fold.  Strands of the %^RED%^web %^ORANGE%^are quite thick and with care, an experienced scavenger can cut these down for use in ropes and various adhesives.  One of the more i"
	"mpressive accomplishments with the web came recently when a family of gnomes found a way to grind the web into a powder that could be thrown at a person to hold them immobile.  It was even claimed tha"
	"t when thrown at an exit, the powder would be able to stop a fleeing foe dead in his or her tracks.%^RESET%^
"
	);
    set_property("lore difficulty",10);
}

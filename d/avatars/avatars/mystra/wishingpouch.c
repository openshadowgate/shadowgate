#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wishingpouch");
	set_id(({ "pouch" }));
	set_short("%^BOLD%^%^WHITE%^Po%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^ch %^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^f %^BLUE%^Wish%^WHITE%^i%^BLUE%^ng%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a po%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^ch %^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^r %^BOLD%^%^WHITE%^ge%^YELLOW%^m%^WHITE%^s%^RESET%^");
	set_long("%^ORANGE%^This appears to be simple pouch like those found around the realm for carrying precious stones.  It is made of a thinned out leather hide and ties closed with a simple piece of rope at the t"
	"op.  It can hold several small stones at a time yet appears to have a special purpose.  A few runic symbols have been burned into the leather and they glow intermittently.%^RESET%^
"
	);
	set_value(5000);
	set_weight(5);
	set_lore("%^BOLD%^%^BLUE%^Studying the runes on the side of the pouch, you discover this pouch is has quite a bit of magical ability to it.  It is made to hold only small stones, and only %^RED%^rubies%^BLUE%^,"
	" %^GREEN%^emeralds %^BLUE%^and %^WHITE%^diamonds%^BLUE%^.  At least three of each stone must reside in the pouch for it's magic to be active.  Once activated the possessor of the pouch can %^YELLOW%^<"
	"pull stones> %^BLUE%^to reach in and grab three of them.  Depending on the combination of stones pulled out, a magical spell will be activated.%^RESET%^
"
	);
    set_property("lore difficulty",30);
}

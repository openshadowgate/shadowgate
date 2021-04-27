#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("treasure");
	set_id(({ "treasure", "loot" }));
	set_short("%^RESET%^%^ORANGE%^a large-sized sack of %^BOLD%^treasure%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a large-sized sack of %^BOLD%^treasure%^RESET%^");
	set_long("%^YELLOW%^This is a large-sized sack of t%^WHITE%^r%^ORANGE%^e%^RESET%^%^ORANGE%^a%^BOLD%^s%^RESET%^u%^BOLD%^r%^ORANGE%^e, lined with quality %^RED%^velvet %^ORANGE%^and stuffed to the brim with an as"
	"sortment of expensive %^GREEN%^valuables%^ORANGE%^, from priceless %^MAGENTA%^a%^RESET%^%^MAGENTA%^r%^BOLD%^tw%^RESET%^o%^BOLD%^%^MAGENTA%^rk %^ORANGE%^to flawless %^CYAN%^g%^RESET%^%^CYAN%^e%^BOLD%^m"
	"%^RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^s%^ORANGE%^, to rare %^RESET%^%^ORANGE%^coins %^BOLD%^and %^WHITE%^j%^RESET%^e%^BOLD%^w%^RESET%^e%^BOLD%^l%^RESET%^r%^BO"
	"LD%^y %^ORANGE%^from around the world. Everything seems to be of the highest quality, even the sack itself, and it must sell for an extraordinary sum.%^RESET%^
"	);
	set_value(1250000);
	set_weight(20);
}

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("treasure");
	set_id(({ "treasure", "loot" }));
	set_short("%^RESET%^%^ORANGE%^a medium-sized sack of %^BOLD%^treasure%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a medium-sized sack of %^BOLD%^treasure%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is a medium-sized sack of %^BOLD%^treasure%^RESET%^%^ORANGE%^, stuffed to the brim with an assortment of valuables, from %^BOLD%^%^MAGENTA%^g%^WHITE%^e%^MAGENTA%^ms %^RESET%^%^"
	"ORANGE%^to %^GREEN%^a%^CYAN%^r%^GREEN%^t%^CYAN%^w%^GREEN%^o%^CYAN%^r%^GREEN%^k %^ORANGE%^to rare %^BOLD%^coins %^RESET%^%^ORANGE%^of odd minting. One could likely make a considerable profit by selling"
	" its contents to the right buyer.%^WHITE%^
"	);
	set_value(62500);
	set_weight(10);
}

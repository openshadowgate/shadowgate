#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^A%^BOLD%^d%^RESET%^%^CYAN%^aman%^BOLD%^t%^RESET%^%^CYAN%^ium%^BOLD%^%^WHITE%^ c%^RESET%^a%^BOLD%^%^WHITE%^g%^RESET%^e%^RESET%^");
	set_id(({ "cage" }));
	set_short("%^RESET%^%^CYAN%^A%^BOLD%^d%^RESET%^%^CYAN%^aman%^BOLD%^t%^RESET%^%^CYAN%^ium%^BOLD%^%^WHITE%^ c%^RESET%^a%^BOLD%^%^WHITE%^g%^RESET%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A%^BOLD%^d%^RESET%^%^CYAN%^aman%^BOLD%^t%^RESET%^%^CYAN%^ium%^BOLD%^%^WHITE%^ c%^RESET%^a%^BOLD%^%^WHITE%^g%^RESET%^e%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This cage is made out of the purest %^BOLD%^%^WHITE%^adamantium%^RESET%^%^CYAN%^. It is large enough to house a large humanoid, and has a door on with an exceedingly %^BOLD%^%^MAGENTA"
	"%^c%^RESET%^%^MAGENTA%^u%^BOLD%^nn%^RESET%^%^MAGENTA%^i%^BOLD%^ng%^RESET%^%^CYAN%^ lock. The cross-link bars prevent more than a hand from extending out. A thief might be willing to %^BOLD%^%^GREEN%^s"
	"teal%^RESET%^%^CYAN%^ it, yet the cage is too heavy to move and no heat short of %^RED%^dragons breath%^CYAN%^ might melt the bars. %^RESET%^
"
	);
	set_value(100000);
	set_weight(500);
}

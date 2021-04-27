#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("table");
	set_id(({ "table", "party table", "tables" }));
	set_short("%^RESET%^%^ORANGE%^The %^BOLD%^%^MAGENTA%^P%^CYAN%^a%^WHITE%^r%^BLUE%^t%^RED%^y %^RESET%^%^ORANGE%^Tables%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^The %^BOLD%^%^MAGENTA%^P%^CYAN%^a%^WHITE%^r%^BLUE%^t%^RED%^y %^RESET%^%^ORANGE%^Tables%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a long , sturdy oak table near the stage. A few mixed dishes have been set out for participants to enjoy.  Resting on the table is a painted sign proclaiming %^BOLD%^%^MAGENTA%^S%^CYAN%^e%^WHITE%^c%^BLUE%^o%^RED%^n%^YELLOW%^d Annual Adventurous Summer Contest!%^RESET%^ %^ORANGE%^There is room on the table for you to leave goodies for the audience.%^RESET%^

AVATAR
	);
	set_weight(200);
	set_value(0);
}

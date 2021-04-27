#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^ORANGE%^aged parchment%^RESET%^");
	set_id(({ "deed", "parchment", "paper" }));
	set_short("%^ORANGE%^aged parchment%^RESET%^");
	set_obvious_short("%^ORANGE%^aged parchment%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This parchment is old and written in the fine flowing script of a master scribe. It is filled with text, though what stands out is the last passage, and the seal of the King of Antioch%^RESET%^%^BOLD%^%^GREEN%^
 
%^RESET%^%^ORANGE%^To Berogar Iras, I bequeth the now Dukedom of Tonovi. These lands and the lands between being under the crown of Torm. May the Duke and the noble forces of Tonovi defend the crown, the cities, and the people 
 
%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
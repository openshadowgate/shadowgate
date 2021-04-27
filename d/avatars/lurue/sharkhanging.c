#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wall hanging");
	set_id(({ "wallhanging", "wall hanging", "hanging", "shark" }));
	set_short("%^RESET%^a %^ORANGE%^c%^RESET%^o%^BOLD%^%^MAGENTA%^p%^RESET%^%^ORANGE%^p%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^r %^RESET%^wall hanging");
	set_obvious_short("%^RESET%^a %^ORANGE%^c%^RESET%^o%^BOLD%^%^MAGENTA%^p%^RESET%^%^ORANGE%^p%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^r %^RESET%^wall hanging");
	set_long(
@AVATAR

%^RESET%^%^ORANGE%^Cut from a sheet of c%^RESET%^o%^BOLD%^%^MAGENTA%^p%^RESET%^%^ORANGE%^p%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^r, this wall hanging is cut in the shape of a %^BOLD%^%^BLACK%^shark%^RESET%^%^ORANGE%^.  Incredibly life like, despite being made out of the polished p%^RESET%^i%^BOLD%^%^MAGENTA%^n%^RESET%^%^ORANGE%^ki%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^h-o%^RESET%^r%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^e color metal, you can see every %^BOLD%^%^BLACK%^scale ridge %^RESET%^%^ORANGE%^and %^RESET%^gill slit%^ORANGE%^, even the eyes are carefully detailed in their design having been brushed to give them a %^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^ll s%^BOLD%^%^BLACK%^h%^RESET%^een%^ORANGE%^ then the rest of the copper.  A small hook on the back allows this plaque to be hung almost anywhere.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(500);
	set_lore(
@AVATAR

This piece of artwork comes out of Tharis.  A recent craft that has come into popularity, using sheets of thinly pressed metal, acid and cutting tines to make three dimensional wall hangings and statues that often have very life like qualities about them.  

Oddly, this particular piece almost hums with living energy, something electric and compelling, despite being an inanimate object.


AVATAR
	);
	set_property("lore difficulty",10);
}

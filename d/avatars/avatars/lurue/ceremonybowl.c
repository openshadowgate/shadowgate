#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("clay bowl");
	set_id(({ "bowl", "clay bowl", "bowl of the eternal cycle", "painted bowl" }));
	set_short("%^RESET%^%^CYAN%^B%^BOLD%^o%^RESET%^%^CYAN%^wl %^ORANGE%^of the %^MAGENTA%^E%^RED%^t%^BOLD%^e%^RESET%^%^RED%^r%^MAGENTA%^n%^BOLD%^%^RED%^a%^RESET%^%^MAGENTA%^l %^ORANGE%^Cy%^BOLD%^%^WHITE%^c%^YELLOW%^l%^WHITE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A %^RED%^b%^MAGENTA%^e%^BOLD%^%^RED%^a%^RESET%^%^RED%^u%^MAGENTA%^t%^ORANGE%^i%^BOLD%^%^WHITE%^f%^YELLOW%^u%^WHITE%^l%^RESET%^l%^ORANGE%^y painted %^BOLD%^%^BLACK%^clay %^RESET%^%^CYAN%^b%^BOLD%^o%^RESET%^%^CYAN%^wl%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Obviously hand crafted this bowl is thick and sturdy, and has been painted with a glaze and fired for a %^RESET%^gl%^BOLD%^%^WHITE%^o%^CYAN%^s%^WHITE%^s%^RESET%^y %^ORANGE%^finish. Aside from the occasional fingerprint it is free of imperfection though even these further attest to the love and care put into crafting this piece of pottery. Painted upon the bowl in a %^RED%^v%^BOLD%^i%^RESET%^%^ORANGE%^b%^YELLOW%^r%^WHITE%^a%^RESET%^%^MAGENTA%^n%^RED%^t %^ORANGE%^array of warm colors are two beautiful scenes, each sharing one half of the circle: %^YELLOW%^Dawn %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^Dusk%^RESET%^%^ORANGE%^. Distinctly %^GREEN%^human%^RESET%^%^ORANGE%^, though somewhat abstract, figures are painted in %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^on the side of sunrise. They are depicted either on their knees praying or standing with their arms raised in jubilation before the rising sun. G%^YELLOW%^o%^WHITE%^l%^YELLOW%^d%^RESET%^e%^ORANGE%^n halos shaped like a starburst surround their heads. Bright oranges, %^RED%^reds %^ORANGE%^and %^YELLOW%^yellows %^RESET%^%^ORANGE%^were used most prominently in this scene. On the opposite side of the bowl a gathering of %^CYAN%^elves %^ORANGE%^also painted in %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^, dance in a broad circle in front of the setting sun. Jagged halos of %^BOLD%^%^WHITE%^s%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^e%^RESET%^r %^ORANGE%^crown their ears and one can almost here the ancient music spurring their graceful dance. %^RED%^D%^MAGENTA%^a%^BOLD%^%^RED%^r%^RESET%^%^RED%^k%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r %^ORANGE%^colors have been used to emphasize that this scene takes place at dusk.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(300);
	set_lore(
@AVATAR
Designed by Azkhadaehlia, an elven follower of Lathander, this bowl was meant to symbolize the ever constant cycle of the day.  Celebrating both the rising dawn and the setting sun, the images depict the glory of Morninglord and the brilliance of his daily journey through the sky.  Created for a ceremony, the bowl was forged and painted by elven artisans whose skill for detail is unsurpassed.

AVATAR
	);
	set_property("lore difficulty",15);
}
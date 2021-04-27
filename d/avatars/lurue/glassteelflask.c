#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("glassteel flask");
	set_id(({ "flask", "container", "glassteel flask" }));
	set_short("%^RESET%^%^CYAN%^G%^MAGENTA%^l%^WHITE%^as%^CYAN%^s %^WHITE%^o%^MAGENTA%^f %^WHITE%^t%^CYAN%^h%^WHITE%^e %^CYAN%^E%^MAGENTA%^n%^WHITE%^dle%^CYAN%^s%^WHITE%^s W%^CYAN%^a%^MAGENTA%^t%^WHITE%^er%^CYAN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^glassteel flask%^RESET%^");
	set_long(
@AVATAR

%^RESET%^This %^CYAN%^glassteel %^RESET%^container is perfectly shaped to fit comfortably in the palm of one's hand with its spout extending beyond the curled fingers.  Formed from a pair of concave ovals, the %^CYAN%^glass %^RESET%^has been crafted with an %^CYAN%^i%^MAGENTA%^n%^WHITE%^tri%^CYAN%^c%^MAGENTA%^a%^WHITE%^te %^CYAN%^d%^MAGENTA%^e%^WHITE%^si%^CYAN%^g%^WHITE%^n that is formed from metal itself, rather then etched onto the surface.  On one side of the flask an %^ORANGE%^old man %^RESET%^sits with his back against a mature %^BOLD%^%^MAGENTA%^c%^RESET%^he%^BOLD%^%^MAGENTA%^r%^RESET%^ry t%^BOLD%^%^MAGENTA%^r%^RESET%^ee flush with blooms.  While the other side features a %^MAGENTA%^young child %^RESET%^standing on tip toe admiring the first %^MAGENTA%^%^BOLD%^b%^RESET%^los%^BOLD%^%^MAGENTA%^s%^RESET%^om of a young sapling.  The smooth ridges of the design blur at the edges, fading away into the curve of the container with liquid precision.  Giving them an %^ORANGE%^aged %^RESET%^appearance, though the flask itself seems new.  At the top, a %^BOLD%^%^WHITE%^silver cap %^RESET%^adorned with a rounded bead of %^BOLD%^%^MAGENTA%^rose quartz%^RESET%^, affixes to the spout, keeping the faintly %^BOLD%^%^MAGENTA%^t%^RESET%^ing%^BOLD%^%^MAGENTA%^e%^RESET%^d liquid secure inside.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(5000);
	set_lore(
@AVATAR
Ordered by Stanshar of the Seneca Restaurant, this flask was enchanted to hold an endless supply of whatever liquid was first placed within it.  A liquid which would be determined at the behest of the one who would carry it.  As a gift for the winner of the Adventurous Summer Contest, Stanshar had the flask designed in remembrance of the story told by Kazi Sonnu who took the Honorable Mention prize with his retelling of an ancient parable from his homelands. 

AVATAR
	);
	set_property("lore difficulty",10);
}

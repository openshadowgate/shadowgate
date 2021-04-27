#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("amber runed cage");
	set_id(({ "cage", "silver cage", "runed cage", "amber runed cage" }));
	set_short("%^BOLD%^%^WHITE%^C%^YELLOW%^e%^BLACK%^l%^WHITE%^l %^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^f t%^YELLOW%^h%^WHITE%^e I%^BLACK%^n%^WHITE%^fi%^RESET%^%^ORANGE%^n%^YELLOW%^i%^WHITE%^te%^RESET%^");
	set_obvious_short("%^RESET%^%^WHITE%^an %^RESET%^%^ORANGE%^a%^YELLOW%^m%^BLACK%^b%^RESET%^%^ORANGE%^er r%^YELLOW%^u%^BLACK%^n%^RESET%^%^ORANGE%^ed %^WHITE%^cage%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^Made from bars of silvery metal lined with a %^RESET%^%^ORANGE%^coppery mesh%^BOLD%^%^WHITE%^, this cage is large enough to contain a horse or other big animal, as well as smaller creatures that might be placed within it.  The %^RESET%^%^ORANGE%^coppery mesh %^BOLD%^%^WHITE%^is thin but resilient bending and flexing while snapping back into place when released.  It is affixed to the silvery bars with %^YELLOW%^amber clamps %^WHITE%^each of which burn with an %^RESET%^%^MAGENTA%^inner power%^BOLD%^%^WHITE%^.  Fused to the silvery metal, the clamps are set barely a hand's breadth apart and feature a curled end onto which the mesh is attached.  Along each of the edges where the cage comes together a set of larger %^YELLOW%^clamps %^WHITE%^can be seen.  These locking mechanism keeps the cage sealed shut and %^RESET%^%^MAGENTA%^activated%^BOLD%^%^WHITE%^, but if one knew the %^RESET%^%^ORANGE%^secret %^BOLD%^%^WHITE%^to it's release, they could open and shut the cage with ease.%^RESET%^

AVATAR
	);
	set_weight(125);
	set_value(50000);
	set_lore(
@AVATAR
Collecting and containing the power, then unleashing it's fury at the exact right moment was an obsession of Theodore LasRadis, a powerful wizard that most considered mad.  In his never ending quest to capture and master the greatest of destructive evocations, he forged this cage, woven from the void of nothing and imbued with the essence of existence.  Its sole purpose being to hold that which could not be contained, and thus, LasRadis believed he would be able to finally conquer the powers that he sought.  The power of pure, raw, unfettered power.  Though completed, the cage was never used by LasRadis.  Some claim that it was because of the side effects caused by the cage itself.  Others say that LasRadis did, in fact, use the cage and that by doing so, destroyed himself.  

AVATAR
	);
	set_property("lore difficulty",20);
}

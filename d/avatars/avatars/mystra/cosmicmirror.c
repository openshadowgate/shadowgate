#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("mirror");
	set_id(({ "mirror", "crystal", "rock" }));
	set_short("%^BOLD%^%^BOLD%^%^YELLOW%^C%^BOLD%^%^RED%^o%^CYAN%^s%^WHITE%^m%^BLUE%^i%^BLACK%^c %^RESET%^%^CYAN%^M%^BLUE%^i%^RESET%^%^ORANGE%^r%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^o%^RESET%^%^ORANGE%^r %^BOLD%^%^RED%^o%^BOLD%^%^CYAN%^f %^BOLD%^%^YELLOW%^C%^RESET%^%^ORANGE%^r%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^z%^BLUE%^i%^BOLD%^%^WHITE%^n%^RESET%^e%^BOLD%^%^CYAN%^s%^CYAN%^s%^RESET%^");
	set_obvious_short("%^RED%^a %^ORANGE%^strange %^BOLD%^%^WHITE%^reflective %^BLACK%^rock%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This strange rock looks like nothing more than the traditional lava rocks you'd find near a volcano.  It is in the shape of a semi-sphere, very rough and jagged around it's convex edge yet extremely smooth and shiney on it's flat side.  You can nearly see a perfect reflection in it's flawless surface.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^An old tome written by Sir William Longbow over 100 years ago spoke of a rock he had seen in his travels with the strange properties of being able to absorb the magic in the air around it.  It was said the perfect surface would take in the magic yet the jagged, curved side would spit it back out, sometimes changing it completely, in any direction it chose.  Very chaotic in device, it was decided that this rock had to have fell from the heavens, possibly a lost item of the gods.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",35);
}

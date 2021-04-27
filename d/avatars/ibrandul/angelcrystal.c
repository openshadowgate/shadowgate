#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RED^%Cryanif%^RESET%^");
	set_id(({ "crystal", "cryanif" }));
	set_short("%^RED%^Cryanif crystal%^RESET%^");
	set_obvious_short("%^RED%^blood red crystal%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This crystal is the size of a child's fist, and is blood red. It has been finely cut and reflects the light into a thousand hues of red. It has been mounted to a %^RESET%^%^BOLD%^fine silver clasp%^RESET%^%^RED%^ shaped into a dragon's claws. Several %^RESET%^%^BOLD%^long feathers%^RESET%^%^RED%^ hand from the mounting, obviously these feathers are much too large for a regular bird, and seem to %^RESET%^glow%^RESET%^%^RED%^ with an inner light.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(10000);
	set_lore(
@AVATAR
Formed from a gem imbued with a thousand rituals, the Cryanif has been crafted to detect and imprison extra-planar creatures. The origins of the gem are unknown, as well as who put the power into the gem. It has been used by both the forces of light and darkness, often falling into obscurity for several decades before reappearing at the sight of a battle between mortals and extra-planar forces.

AVATAR
	);
	set_property("lore difficulty",10);
}
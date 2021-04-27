#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("shiny object");
	set_id(({ "object", "stone", "glowing stone" }));
	set_short("%^BOLD%^%^MAGENTA%^D%^YELLOW%^a%^MAGENTA%^w%^YELLOW%^n%^MAGENTA%^'%^YELLOW%^s L%^MAGENTA%^i%^YELLOW%^g%^MAGENTA%^h%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^YELLOW%^sh%^MAGENTA%^i%^YELLOW%^ny%^WHITE%^ stone%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^This stone is small, no more then a pebble one might find along the road.  It's white surface is marred only by a tiny speck of yellow coloration that seems fairly ordinary until it is held.  Then it %^YELLOW%^gl%^MAGENTA%^o%^YELLOW%^ws br%^MAGENTA%^i%^YELLOW%^gh%^MAGENTA%^t%^YELLOW%^ly %^WHITE%^with the radiance of the %^YELLOW%^sun's %^MAGENTA%^morning %^YELLOW%^light%^WHITE%^!%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
Some claim these stones are pieces of the sun fallen to the ground.  Others say they are the stones where Lathander has set foot upon the mortal world.  Still others claim they are natural phenomena.  Whatever has created them, the simple act of touching them causes them to glow with a light as brilliant as the morning's first rays of dawn.  Prized by those of the Dawn Lord, they are said to gift whatever they are set into some of the properties of the Morninglord's gift to all mankind.

AVATAR
	);
	set_property("lore difficulty",13);
}
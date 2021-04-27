#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("spurs");
	set_id(({ "spurs", "set of spurs", "metal spurs" }));
	set_short("%^RESET%^A set of %^BOLD%^%^BLACK%^metal %^RED%^spurs%^RESET%^");
	set_obvious_short("%^RESET%^A set of %^BOLD%^%^BLACK%^metal %^RED%^spurs%^RESET%^");
	set_long(
@AVATAR
These are a set of %^BOLD%^%^BLACK%^metal %^RED%^spurs %^RESET%^designed to be worn on the back of a horseman's boot.  They come in pairs and consist of a u-shaped metal bracket that slides around the heel of the boot and several %^RESET%^%^ORANGE%^leather straps %^RESET%^which are designed to hold them in place.  The spur proper consists of a little %^BOLD%^%^BLACK%^metal wheel %^RESET%^that resembles a sprocket.  The little nobs on the wheel have been sharpened as to allow the rider to urge its beast on.  They are quite light but nonetheless well-made.

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",0);
}



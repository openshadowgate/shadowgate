#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("orb");
	set_id(({ "orb", "strange orb", "crystal orb", "red crystal orb", "red orb" }));
	set_short("%^RED%^Red cry%^CYAN%^s%^RESET%^%^RED%^tal orb%^RESET%^");
	set_obvious_short("Red crystal orb");
	set_long(
@AVATAR
This orb is made from a very strange crystal.  The hue of the crystal is a %^RED%^rust red%^RESET%^ with flecks of a lighter and more brilliant hue.  The inside of the crystal is filled with a %^BOLD%^%^BLACK%^darker mist%^RESET%^.  The color and composition of the mist is skewered by the crystal, preventing you from determining what it actually is.  A tangible aura hangs close to the orb, offering you an almost sick feeling from just glancing at or even being near it.

AVATAR
	);
	set_weight(8);
	set_value(4000);
}
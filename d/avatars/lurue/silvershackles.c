#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("shackles");
	set_id(({ "shackles", "silver shackles" }));
	set_short("%^BOLD%^%^WHITE%^a set of four silver shackles%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a set of four silver shackles%^RESET%^");
	set_long(
@AVATAR
These shackles are really only four unattached cuffs, two for the ankles and two for the wrists.  The odd thing about them is they are not attached by any form of chain and yet they cannot be moved further apart then a grown person could move while wearing them.  Further, the bands appear to be solid silver without any trace upon them.  There doesn't even appear to be a way to open them, yet they seem far too small to put over one's hands.

AVATAR
	);
	set_weight(2);
	set_value(0);
}
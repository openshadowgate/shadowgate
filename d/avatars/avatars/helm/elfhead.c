#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("head");
	set_id(({ "head", "elven head", "shrunk head" }));
	set_short("%^RESET%^%^ORANGE%^a shrunk elven head (missing an ear)%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a shrunk elven head (missing an ear)%^RESET%^");
	set_long(
@AVATAR
This is a preserved and shrunk elven head. A few long, dark tresses of hair still remains and the skin is tightly stretched over the skull. Most of the facial features have disappeared in the process of shrinking it and the only thing that seems odd is that the left ear is missing.

AVATAR
	);
	set_weight(2);
	set_value(0);
}
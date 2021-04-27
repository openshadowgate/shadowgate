#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jade monkey");
	set_id(({ "statue", "jade statue", "monkey", "jade monkey" }));
	set_short("%^RESET%^%^GREEN%^Jade Monkey%^RESET%^");
	set_obvious_short("jade statue");
	set_long(
@AVATAR
This is a small statue of a monkey made of jade, approximately twenty inches high.  Its lips are curled into a grimace of pain, and its ears have a distinctive elven point, although they are not very lengthy.  The elegance of the statue's elven ears contrast with the way its knuckles appear to be helping support the monkey's weight.  There appear to have been gems set in both of its eye sockets, but they have since fallen out or been pried out.

AVATAR
	);
	set_weight(30);
	set_value(550);
	set_lore(
@AVATAR
Legend tells of a great evil imprisioned within a jade monkey, whether this is the actual jade monkey or what evil is imprisioned in it is unknown.

AVATAR
	);
}
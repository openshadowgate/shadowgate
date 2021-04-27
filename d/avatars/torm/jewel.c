#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Jewel");
	set_id(({ "jewel", "gem" }));
	set_short("%^BOLD%^%^WHITE%^Glittering Jewel%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a large precious stone that has been cut and polished so that it glitters in the light.  It looks like it was once set into a larger item, but no trace of what that might have been now remains.  Even to an untrained eye this jewel looks to be very valuable.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(3500);
	set_lore(
@AVATAR
This gem looks familiar to anyone who has seen the stone engraving above the House of the Jewelled Gauntlet, or who has heard the tale of the Headless Paladin.  Whether this is the same gem as the one mentioned in that tragic tale, or simply a good imitation, who can say.

AVATAR
	);
	set_property("lore difficulty",1);
}
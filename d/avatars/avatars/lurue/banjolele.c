#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("darkwood banjolele");
	set_id(({ "banjolele", "darkwood banjolele", "wood banjolele" }));
	set_short("%^BOLD%^%^BLUE%^a darkwood banjolele%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a darkwood banjolele%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLUE%^This guitar-like instrument is about a foot and a half long made out of a dark wood grown in Tharis Forest and accented with several pieces of delicate %^WHITE%^silver scrollwork%^BLUE%^.  The skin stretched across the round body appears to be very thin but strong and is likely made of goat hide.  The neck of the banjolele is likewise made of dark wood and features several small wooden pegs at one end that secure a set of five %^WHITE%^silver strings%^BLUE%^.  It's a stunning piece of work and the sound is crisp and uplifting.%^RESET%^


AVATAR
	);
	set_weight(3);
	set_value(500);
	set_lore(
@AVATAR
This banjolele was given to a young and upcoming bard who charmed a crowd during a dreary day.  Given to him by one of the Master Bards who makes their home at the Crown and Castle, his jokes and music was said to have been well received by the crowd he performed for.

AVATAR
	);
	set_property("lore difficulty",10);
}
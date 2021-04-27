#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Alliare Scroll1");
	set_id(({ "Scroll", "scroll" }));
	set_short("Scroll");
	set_obvious_short("Scroll");
	set_long(
@AVATAR
This scroll has been written on, you could easily read it.

AVATAR
	);
	set("read",
@AVATAR
Zellion,

%^YELLOW%^As per your request I have inquired about the demonlord Alliare DoomRiden.  Some of my findings were disturbing, I hope this information proves helpful my dear friend.

%^YELLOW%^Alliare DoomRiden, as far as I can tell is several eons old.  Apparently at one time he was a general in the army of a Demi-God, possibly even created by that Demi-God.  The Demi-God was Archlissis.  Alliare served Archlissis until Archlissis perished several thousand years ago.  After that period of time Alliare had several encounters with other demons, he was frequently involved with great battles.  Somewhere along the line he obtained the hammer of souls.

%^YELLOW%^I shall continue later...%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
}
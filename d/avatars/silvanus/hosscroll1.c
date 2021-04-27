#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Hammer of Souls Scroll1");
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
I have researched this Hammer of Souls you have inquired about.  The information I've found is interesting, though very brief.  It may be of some value to you.
As far as I can tell the hammer was made thousands of years ago, by a demi-god named Archlissis.  Archlissis apparently made the hammer to kill one of his enemies, another demi-god.  Archlissis was slain by one in his own army and the hammer stolen.  The hammer vanished for sometime and did not reappear until several hundred years later.  When it reappeared it was in the possession of Alliare DoomRiden, a lesser demonlord of the abyss.  
Alliare was the last known possessor of it, it's not sure if someone else possessed it while it was hidden or not, but Alliare was the last known possessor.  History of the hammer suggests that it has the power to entrap souls of it's victims.  Some rumors suggest that up to four souls can be trapped within the hammer at the same time.  The souls are reportedly kept within the gem in the head of the hammer.  I've never saw the hammer, but I'm assuming it would be possible to probably extract that gem from the hammer and then do research on it or possibly get the souls out of it.
I hope this helps, my dear friend
%^BOLD%^%^BLACK%^                    Yuliwth Balza

AVATAR
	);
	set_weight(1);
	set_value(10);
}
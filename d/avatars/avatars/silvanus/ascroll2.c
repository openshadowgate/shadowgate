#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Alliare Scroll2");
	set_id(({ "scroll", "Scroll" }));
	set_short("Scroll");
	set_obvious_short("Scroll");
	set_long(
@AVATAR
This scroll has been written on, you could easily read it.

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^Significantly he came to this world about 400 years ago, for a period of time that could have been as great as 100 years.  It's not entirely clear what he did while he was here, it is certain that he had the hammer though, as mages of that time were interested in what it was and history of the far western world reveals that the hammer was possessed by a demon who along with some others, terrorized the land.

%^YELLOW%^At the end of that period of time he was defeated by a group of companions, though he fell one of those companions before he died, the one he defeated was none other than Nimmi Carendore.

%^YELLOW%^He was banished back to the abyss and was apparently under the control of a more powerful demon, who used him as a servant.  He waited there, with his hammer, until recently, when he reportedly came back to this world.

%^YELLOW%^Please take caution if you are dealing with this fiend, my friend.

Your dear and concerned friend,

%^RED%^                    Khellaz Slafon
%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
}
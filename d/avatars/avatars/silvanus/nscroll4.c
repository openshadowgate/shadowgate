#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Nimmi Scroll4");
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
During those years he and his companions became known, they destroyed almost everything in their way and left a scar in the land that has yet to completely heal.  He may have been at the point of almost achieving his goal, but suddenly he was killed, by the very demonic creature, which I've found was known as Alliare DoomRiden, which was helping him and his companions.  His companions apparently banished the creature and then they too disappeared.  Miraculously the land was rid of Nimmi Carendore and his companions.

Some creatures say he was possessed by Alliare, after Alliare killed him and that Alliare frequently tormented him.

I hope all is well with you my dear friend, this one you have inquired about is indeed strange and definately wicked.

%^BLUE%^                  Ikalian Dolsy

AVATAR
	);
	set_weight(1);
	set_value(10);
}
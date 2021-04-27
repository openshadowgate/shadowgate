#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Hammer of Souls Scroll2");
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
I've never saw the hammer, but I'm assuming it would be possible to probably extract that gem from the hammer and then do research on it or possibly get the souls out of it.

Doing anything to the hammer and gem, would require careful preparation and caution.

I hope this helps, my dear friend

%^BOLD%^%^BLACK%^                 Yuliwth Balza

AVATAR
	);
	set_weight(1);
	set_value(10);
}
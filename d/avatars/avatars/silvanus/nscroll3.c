#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Nimmi Scroll3");
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
Unfortunately they found a man there who was willing to help them or at least advise them on what they should do.  The man, who I am not sure who is, advised them to visit an altar deep within a forest to the west of the mountains.  It's uncertain how long it took for them to get there, but once they did they encountered the specter of something. 

What happened while they were there is a blur, the next sighting of them was when they struck the little village again, with the aide of some demonic creature, that possessed some odd hammer.  They destroyed everything in the town and there Nimmi vowed to destroy Li'Linmai.  He had been convinced somehow that he needed to ascend to her power in order to do that, so for the next decades of his life he was on a quest to become a demi-god.

I shall finish later.

AVATAR
	);
	set_weight(1);
	set_value(10);
}
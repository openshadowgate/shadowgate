#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Nimmi Scroll1");
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

I have, as you requested researched this man known as Nimmi Carendore.  I have found some very interesting and quite disturbing information.

Nimmi Carendore died somewhere between 300 to 350 years ago.  It was only in the last 50 years of his life that he became known.  His story is an odd one, I shall explain.

Nimmi and several others, that considered themselves friends and adventurers lived in a small village somewhere in the western edges of the world.  Nimmi was married to one Elishion Carendore, a female human priestess of the goddess Li'Linmai.  Nimmi was not in love with her though, he was in love with a much younger woman, who had been deemed a half-breed, in fact, he was also involved with an affair with her.

I shall continue later

AVATAR
	);
	set_weight(1);
	set_value(10);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("flowers");
	set_id(({ "flowers", "flower", "bouquet", "card", "note", "roses" }));
	set_short("%^RESET%^%^BOLD%^Bouquet of Flowers%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This is a pretty bouquet of white roses.  There are about a dozen of them, and they are just beginning to open up.  A card is pinned to the side of the bouquet.

AVATAR
	);
	set("read",
@AVATAR
I am truly sorry for your loss.  Accept these roses with my deepest condolences.

Signed,

Decius Vatarri

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(50);
	set_lore(
@AVATAR
What's to know, its a bouquet of flowers!

AVATAR
	);
	set_property("lore difficulty",0);
}
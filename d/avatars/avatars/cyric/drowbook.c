#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("spellbook");
	set_id(({ "book", "spell book", "spellbook", "tome" }));
	set_short("Spellbook");
	set_obvious_short("book");
	set_long(
@AVATAR
This is what appears to be a ruined spellbook.  Water has spilled on many of the pages, running the ink, and it appears as if some small animal shredded many of the pages for a nest (as well as marked the book as its own with a pungent stench).  Some words are still legible on the inside cover.

AVATAR
	);
	set("read",
@AVATAR
operty of Klyzzath, first apprentice of headwizard Drx$&(#% to       house Ul$&&*


AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(0);
}
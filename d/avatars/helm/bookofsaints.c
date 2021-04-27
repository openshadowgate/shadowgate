#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("book");
	set_id(({ "book", "book of saints" }));
	set_short("%^BOLD%^%^BLACK%^A tattered old book%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A tattered old book%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These are the remains of a tattered old book where only a few pages remain. The ink is smudged and the pages are torn and dirty, basically it is all but readable.



%^BOLD%^%^BLACK%^On the front cover you can still see these words: 'S-in-s of t-e Rea-m-'


AVATAR
	);
	set("read",
@AVATAR
You can't read this since you can't possibly see what it says.

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(0);
}
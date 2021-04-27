#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("book");
	set_id(({ "book" }));
	set_short("%^BOLD%^%^BLACK%^A tattered old book%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A tattered old book%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is the front cover of an old tattered book. Only a few pages remain now and the ink is smudged and the papers are torn and dirty. The pages are unreadable.

%^BOLD%^%^BLACK%^On the front cover you can still see the words: 'Sain-s -f -he --alms'%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
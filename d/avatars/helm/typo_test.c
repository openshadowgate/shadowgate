#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("dictionary");
	set_id(({ "dictionary" }));
	set_short("%^BOLD%^%^BLUE%^Oxford Advanced Learner's Dictionary%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^Oxford Advanced Learner's Dictionary%^RESET%^");
	set_long(
@AVATAR
This is a dictionary.

AVATAR
	);
	set("read",
@AVATAR
Wow, it contains like a lot of text.

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(127);
	set_property("lore difficulty",0);
}
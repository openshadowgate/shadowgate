#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("case of tools");
	set_id(({ "tools", "thief's tools", "case of tools" }));
	set_short("%^RESET%^%^ORANGE%^A soft leather case of tools%^RESET%^");
	set_long(
@AVATAR
This is a small, soft %^ORANGE%^leather case%^RESET%^ that can be rolled and tied closed with %^ORANGE%^leather thongs%^RESET%^.  The case, when fully opened, reveals rows of pouches and slots filled with various %^BOLD%^skeleton keys%^RESET%^, %^CYAN%^long metal picks %^RESET%^and %^BLUE%^pries%^RESET%^, a small %^YELLOW%^handsaw%^RESET%^(for especially stubborn locks.  It even has a %^GREEN%^small hammer%^RESET%^ with a metal wedge.  These tools would probaly aid any locksmith.

AVATAR
	);
	set_weight(1);
	set_value(65);
	set_lore(
@AVATAR
These locksmith tools are often carried by rogues who need to find more delicate ways around locks than bashing or breaking them open.  This basic set is one that almost any true rogue carries with them.

AVATAR
	);
	set_property("lore difficulty",3);
}
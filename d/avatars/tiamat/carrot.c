#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("weird glass");
	set_id(({ "glass", "carrot" }));
	set_short("%^BOLD%^%^WHITE%^glass with a %^RESET%^%^ORANGE%^carrot%^RESET%^%^BOLD%^ sticking out%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^glass with a %^RESET%^%^ORANGE%^carrot%^RESET%^%^BOLD%^ sticking out%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Well, this is weird.  It looks like a %^ORANGE%^carrot%^RESET%^ sticking out of a glass.  A very nice %^BOLD%^crystal%^RESET%^ glass, filled with %^BOLD%^%^BLUE%^blue liquid%^RESET%^.  There is something sandy on the bottom too.  Did you notice the %^ORANGE%^carrot %^RESET%^sticking out?  What kind of person would do such a thing?  It smells vaguely like cedar chips too.  Weird.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(400);
	set_lore(
@AVATAR
There is a magical aura around this strange setup.  It is being used as a focus for some kind of spell.  The aura would indicate it is an illusion of some kind.

AVATAR
	);
	set_property("lore difficulty",20);
}

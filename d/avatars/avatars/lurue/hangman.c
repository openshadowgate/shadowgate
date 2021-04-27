#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("platform");
	set_id(({ "plat" }));
	set_short("%^RESET%^%^ORANGE%^A hangman's platform%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A hangman's platform%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This large structure is built a few feet away from the walls of the jail.  It appears to be a hangman's platform made from wood.  Six stairs lead up to the landing above which is supported a beam with a noose hanging from it.  A trap door is below the noose ready to be opened at the hangman's whim.%^RESET%^

AVATAR
	);
	set_weight(150);
	set_value(0);
}
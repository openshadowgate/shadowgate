#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("disc");
	set_id(({ "disc" }));
	set_short("%^BOLD%^%^YELLOW%^D%^RESET%^i%^BOLD%^%^YELLOW%^sc of %^BOLD%^%^CYAN%^Eternity%^RESET%^");
	set_obvious_short("A very small glass disc");
	set_long(
@AVATAR
This is a very small glass disc with a rune upon it. The rune is that of a scimitar. It looks as though it can be placed somewhere.

AVATAR
	);
	set_weight(0);
	set_value(100);
}
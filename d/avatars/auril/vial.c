#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("vial");
	set_id(({ "vial" }));
	set_short("%^BOLD%^%^BLUE%^A vial with swirling liquid%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A vial with swirling liquid%^RESET%^");
	set_long(
@AVATAR
The mixture inside is odd in color. Almost as blue as the sky. A color very rare to see within the underground. On the side, there is something in scribed.

AVATAR
	);
	set("read",
@AVATAR
Antitode

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(0);
}
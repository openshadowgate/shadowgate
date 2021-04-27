#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("disc");
	set_id(({ "disc" }));
	set_short("%^BOLD%^%^GREEN%^A small circular disc%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A small circular disc%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^A small circular disc%^RESET%^ that has an inscription writton on it.

AVATAR
	);
	set("read",
@AVATAR
Rub and request

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(5);
}
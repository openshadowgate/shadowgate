#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wand");
	set_id(({ "wand" }));
	set_short("%^RESET%^%^CYAN%^A smooth light blue wand%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A smooth light blue wand%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This beautifully crafted wand was made of the most exceptionately crafted wood and dyed blue.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Made by: %^RESET%^%^WHITE%^Stefano Esposair

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
}
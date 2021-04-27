#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("death knight's skull");
	set_id(({ "skull", "death knight skull", "knight skull" }));
	set_short("%^BOLD%^%^BLACK%^Skull From a Death Knight%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Skull%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This skull is ancient, at least several hundred years old.  A few spots of rotting flesh remain on it.  You get a very eerie feeling looking at it.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(0);
}
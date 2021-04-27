#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("elven child");
	set_id(({ "child", "elf child", "small child" }));
	set_short("%^BOLD%^%^WHITE%^A small elven child wrapped in swaddling clothes%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A small elven child wrapped in swaddling clothes%^RESET%^");
	set_long(
@AVATAR
This is a cute little elven baby of perhaps a year old.  She is carefully wrapped tightly in a blanket to keep her from catching cold.  Even at this age, she is still possessive of all the elven features, namely pointy ears and a finely chisled face (though the baby fat masks this some).  The hint of little golden ringlets can be seen atop her head and her eyes are a crisp blue.

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_property("lore difficulty",0);
}
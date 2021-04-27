#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("body");
	set_id(({ "body", "upper body", "corpse" }));
	set_short("%^RESET%^%^RED%^The upper body of a young girl%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^The upper body of a young girl%^RESET%^");
	set_long(
@AVATAR
This is the upper body and head of a young blonde haired girl, it is pale and lifeless. Bite and clawmarks of a large feline animal is clearly visible on her chest.

AVATAR
	);
	set_weight(30);
	set_value(0);
	set_property("lore difficulty",0);
}
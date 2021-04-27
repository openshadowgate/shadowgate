#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Snake's Fang");
	set_id(({ "fang", "snakes fang", "snake fang", "snake's fang" }));
	set_short("%^BOLD%^%^GREEN%^Snake's Fang%^RESET%^");
	set_obvious_short("snake's fang");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This fang looks like it has recently been ripped from the mouth of a snake.  Judging from the drops of liquid that occassionally come forth from the end of it, it's safe to assume it was a poisonous snake.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
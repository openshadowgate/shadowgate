#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("moonstone rod");
	set_id(({ "moonstone rod", "rod" }));
	set_short("%^BOLD%^%^WHITE%^m%^BLACK%^o%^RESET%^o%^WHITE%^%^BOLD%^ns%^BLACK%^t%^RESET%^o%^BOLD%^%^WHITE%^ne r%^BLACK%^o%^WHITE%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^m%^BLACK%^o%^RESET%^o%^WHITE%^%^BOLD%^ns%^BLACK%^t%^RESET%^o%^BOLD%^%^WHITE%^ne r%^BLACK%^o%^WHITE%^d%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This thin rod is made from polished m%^BLACK%^o%^RESET%^o%^WHITE%^%^BOLD%^ns%^BLACK%^t%^RESET%^o%^BOLD%^%^WHITE%^ne.  It is about five inches long and is barely two inches in diameter.  It appears very fragile and could probably break quite easily.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
}
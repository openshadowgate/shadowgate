#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Gem of Souls");
	set_id(({ "gem", "stone", "jewel", "gem of souls", "stone of souls", "crystal", "crystal of souls" }));
	set_short("%^BOLD%^%^BLACK%^Gem of Souls%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^abyssal black gem%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This gem is a %^CYAN%^translucent%^BOLD%^%^BLACK%^ black and is almost two inches in diamater.  It is completely rounded and has been smoothed to utter %^MAGENTA%^perfection%^BOLD%^%^BLACK%^.  You can see that the inside of it is divided up into four segments and inside two of the segments is a swirling %^BOLD%^%^WHITE%^mist%^BOLD%^%^BLACK%^.  On one side of the gem there is an %^RED%^inscription%^BOLD%^%^BLACK%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^To %^BOLD%^%^GREEN%^summon%^BOLD%^%^BLACK%^ forth the spirits of the entrapped....%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(900);
}
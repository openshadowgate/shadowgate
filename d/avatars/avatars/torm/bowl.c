#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bowl");
	set_id(({ "bowl", "wooden bowl" }));
	set_short("%^BOLD%^%^WHITE%^Ha%^RESET%^%^ORANGE%^nd%^BOLD%^%^WHITE%^-craft%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^d %^RESET%^%^ORANGE%^woode%^BOLD%^%^WHITE%^n bowl%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a simple wooden bowl carved from a single piece of white oak.  The inner and outer surfaces have been smoothed ready for use.  The g%^RESET%^%^ORANGE%^ra%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^ of the woo%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^ provides the natural decoration on this rustic tableware.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(150);
	set_lore(
@AVATAR
This is a simple wooden bowl, a good example of traditional woodland craftsmanship

AVATAR
	);
}
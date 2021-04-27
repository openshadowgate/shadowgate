#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jasmine bloom");
	set_id(({ "jasmine bloom", "bloom", "jasmine", "flower" }));
	set_short("%^BOLD%^%^WHITE%^j%^MAGENTA%^a%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^mi%^RESET%^%^MAGENTA%^n%^BOLD%^%^WHITE%^e b%^MAGENTA%^l%^RESET%^%^MAGENTA%^o%^BOLD%^%^WHITE%^om%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^j%^MAGENTA%^a%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^mi%^RESET%^%^MAGENTA%^n%^BOLD%^%^WHITE%^e b%^MAGENTA%^l%^RESET%^%^MAGENTA%^o%^BOLD%^%^WHITE%^om%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This life like jasmine bloom is made from shards of carefully cut %^BOLD%^%^WHITE%^o%^MAGENTA%^p%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^l %^RESET%^%^MAGENTA%^and fine sheets of paper-thin %^WHITE%^%^BOLD%^silver%^RESET%^%^MAGENTA%^.  Delicate and beautiful, the blossom opens and closes with the night, blooming fully under the %^RESET%^moonlight%^MAGENTA%^, and closing during the day.  The pale radiance of the stones even appears to glow with a holy light.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_lore(
@AVATAR
Created as a gift for Selune's temple in 234 SG, this crystal blossom was an ordinary piece of artwork until it was placed upon the altar of Selune.  Then, many claim that Selune herself was so impressed with the gift and beauty that she bestowed life into it, causing it to bloom each night and provide her radiance no matter how far away the carrier was from the moonlight.

AVATAR
	);
	set_property("lore difficulty",32);
}
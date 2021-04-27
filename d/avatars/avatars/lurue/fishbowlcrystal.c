#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("crystal");
	set_id(({ "shard", "crystal", "crystal shard", "shard of crystal" }));
	set_short("%^BOLD%^%^CYAN%^crystal shard%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This shard of crystal isn't very big.  Just a chunk off of a much larger piece.  Smooth on either side and jagged along the edges, it appears almost to be a piece of glass, except that the material is clearly a light blue crystal.  Its probably worth a good chunk of money, if you found the right buyer.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(5000);
	set_lore(
@AVATAR
Broken from the crystal fishbowl where Klauth kept one of his prizes for a time, these fragments are all but useless except to a jeweler or other artisan who could polish them up and use them in various bits of work.

AVATAR
	);
	set_property("lore difficulty",10);
}

#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Crystal Skull");
	set_id(({ "skull" }));
	set_short("%^BOLD%^%^WHITE%^Crystal Skull of S%^CYAN%^o%^RESET%^%^CYAN%^u%^BOLD%^%^WHITE%^ls%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Crystal Skull of S%^CYAN%^o%^RESET%^%^CYAN%^u%^BOLD%^%^WHITE%^ls%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a bit of pure crystal quartz, carved into a skull about the size of large fist.  The skulls bears no flaws or cracks in any way, and strange runes have been carved along its entire surface.  Swirling within the skull is a dull %^CYAN%^mi%^RESET%^%^CYAN%^st%^BOLD%^%^WHITE%^ barely visible until held before the light.  It feels warm to the touch and pulses with a strange energy.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
}
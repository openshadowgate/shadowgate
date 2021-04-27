#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("shar statue");
	set_id(({ "statue" }));
	set_short("%^BOLD%^%^BLACK%^Statue of %^RESET%^%^MAGENTA%^S%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Statue of %^RESET%^%^MAGENTA%^S%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The intricate statue carved before you is a likeness of the goddess of Darkness and Loss, %^BOLD%^%^RED%^Shar%^BOLD%^%^BLACK%^. She has long dark silken hair that flows
%^BOLD%^%^BLACK%^freely and a long dark cloak covering her beautiful features. Beautiful %^RESET%^%^MAGENTA%^amythest %^BOLD%^%^BLACK%^eyes peer out omniously. The statue is both hypnotic and terrifying.


%^BOLD%^%^YELLOW%^A plaque sits near the bottom.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^The eternal night shall always outweigh the feint glow of the moon.

AVATAR
	);
     set("langage","str");	set_weight(450);
	set_value(0);
}
#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("giant sapphire");
	set_id(({ "gem", "sapphire", "eye" }));
	set_short("%^BOLD%^%^BLUE%^Eye of St%^WHITE%^o%^BLUE%^rms%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^Eye of St%^WHITE%^o%^BLUE%^rms%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Superficially, the Eye looks like a dark fist-sized sapphire, jewelled into a princess cut.  On close inspection, you detect movement from within from your handling.  When you peer deeply into the sapphire, you faintly make out a whirling %^WHITE%^c%^BLUE%^y%^CYAN%^cl%^WHITE%^on%^BLUE%^e.
%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(10000);
}
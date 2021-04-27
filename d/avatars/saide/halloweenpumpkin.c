#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("halloween pumpkin");
	set_id(({ "pumpkin", "halloween pumpkin" }));
	set_short("%^ORANGE%^A large, flaming pumpkin%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is a large pumpkin grown from deep inside Saide's Insane Asylum.  It has been carved to have a large smiling face and the phrase "%^B_CYAN%^%^YELLOW%^HAPPY HALLOWEEN%^RESET%^%^ORANGE%^" is written all over it in dark letters.  The strangest thing about this pumpkin is that it is lit ablaze and you imagine it sticking to you wouldn't feel too good.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);

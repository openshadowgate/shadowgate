#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("schooner key");
	set_id(({ "key" }));
	set_short("%^YELLOW%^a brass key%^RESET%^");
	set_obvious_short("%^YELLOW%^a brass key%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This is a brass key that fits easily in your hand.  Etched onto the top part is the picture of a two masted schooner.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}

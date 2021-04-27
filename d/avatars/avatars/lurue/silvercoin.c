#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("coin");
	set_id(({ "coin", "silver coin" }));
	set_short("%^BOLD%^%^WHITE%^a silver coin%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a silver coin%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This silver coin looks like it could be from almost anywhere, and spend as easily too.  It would be of no note except that one side is smooth to the touch and the other features a very stylized %^BLACK%^wolf figure %^WHITE%^on the other.  There are no markings to indicate where it came from or why it was stamped this way.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^There is little to be figured out from this coin, but the wolf figure might lead one to more information, if they knew where to look.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",5);
}

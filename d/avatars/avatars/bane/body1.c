#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("A burned and ravaged body");
	set_id(({ "body", "corpse" }));
	set_short("%^BOLD%^%^RED%^A burned and ravaged body%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A burned and ravaged body%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This looks to have once been something similar to a human, though now burned and massacred in ways to make it to hard to tell. The entire body is black with burns. Hundreds of cuts can be seen over the body as if done to torture the victim before its death. The ears have been completely removed and the face smashed in as if to hide the identity of the victim. All forms of clothing seemed to have been burned along with the body, only a frayed piece here and there remain. Carved into the center of the chest is the symbol of %^BOLD%^%^BLACK%^Bane%^RESET%^%^RED%^.%^RESET%^

AVATAR
	);
	set_weight(100);
	set_value(0);
}
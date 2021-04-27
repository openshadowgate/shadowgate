#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("scroll case");
	set_id(({ "scroll case", "locked case", "adamantium case" }));
	set_short("%^BOLD%^%^WHITE%^adamantium scroll case%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^adamantium scroll case%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^A slender tube made from adamantium, this case appears to have been created with the idea of keeping its content safe and secure from prying eyes.  The tube features a pair of locking mechanisms at either end which appear to both need to be unlocked in order to reach what is contained within.  Without the key though, this would be a difficult thing to pick.%^RESET%^


AVATAR
	);
	set_weight(2);
	set_value(1000);
}